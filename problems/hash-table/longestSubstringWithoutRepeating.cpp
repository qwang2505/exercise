#include "../include.h"

/**
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int n = s.length();
    int start = 0;
    int maxLen = 0;
    for (int i=0; i < n; i++) {
        char c = s[i];
        if (m.find(c) != m.end()) {
            if (m[c] >= start) {
                start = ++m[c];
            }
        }
        m[c] = i;
        if (i - start + 1 > maxLen) {
            maxLen = i - start + 1;
        }
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
}
