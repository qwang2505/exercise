#include "../include.h"

/**
 * You are given a string, s, and a list of words, words, that are all of the same length. 
 * Find all starting indices of substring(s) in s that is a concatenation of each word 
 * in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 */

// 比较容易想到的解法，但是是错误的，因为如果words中包含重复的单词，
// 使用map的方法就失效了。这是一种没有考虑到的情况。
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> output;
    if (words.size() == 0 || s.length() == 0) {
        return output;
    }
    int wordSize = words[0].length();
    if (wordSize > s.length()) {
        return output;
    }
    map<string, int> m;
    for (int i=0; i < words.size(); i++) {
        m[words[i]] = -1;
    }
    int start = -1;
    int i = 0;
    while (i < s.length() - wordSize) {
        string temp = s.substr(i, wordSize);
        if (m.find(temp) == m.end()) {
            start = -1;
            i += wordSize;
            continue;
        }
        if (start == -1) {
            start = i;
        }
        if (m[temp] >= start) {
            start = m[temp] + wordSize;
        }
        m[temp] = i;
        if ((i - start)/3 + 1 == words.size()) {
            output.push_back(start);
        }
        i += wordSize;
    }
    return output;
}

int main() {
    string a[] = {"foo", "bar"};
    vector<string> input(a, a+sizeof(a)/sizeof(a[0]));
    //vector<int> indics = findSubstring("barfoothefoobarman", input);
    vector<int> indics = findSubstring("barfoobarthefoobarman", input);
    printVector(indics);
}
