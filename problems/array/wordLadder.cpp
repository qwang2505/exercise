#include "../include.h"

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of 
 * shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a set of strings). 
 * Please reload the code definition to get the latest changes.
 */


/** ===================== BFS solution ============================= */

// 运用宽度优先搜索的算法，再leetcode中会time limit exceeded
// 好好理解宽度优先搜索的过程，如何寻找相邻节点，如何标记相邻节点，等等

// 寻找相邻节点，添加到对列中，下一次访问
void addNextWords(string word, vector<string>& wordDict, queue<string>& toVisit) {
    // 开始元素如果在词典中存在，将其删除。这一步应该不一定是有必要的
    vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), word);
    if (it != wordDict.end()) {
        wordDict.erase(it);
    }
    // 循环替换每个字母，如果组成的单词在词典中存在，将其加入到对列中
    for (int p = 0; p < (int)word.length(); p++) {
        char letter = word[p];
        for (int k = 0; k < 26; k++) { 
            word[p] = 'a' + k;
            it = find(wordDict.begin(), wordDict.end(), word);
            if (it != wordDict.end()) {
                toVisit.push(word);
                wordDict.erase(it);
            }
        }
        word[p] = letter;
    }
}

// 使用BFS来求解，算是一种比较简单的方法，比较容易想到的方法。
// 好好理解BFS的使用场景，针对类似问题，应该能快速想到用BFS来解答
int ladderLengthBFS(string beginWord, string endWord, vector<string>& wordDict) {
    // 对列中存储每次迭代待访问的节点
    queue<string> toVisit;
    // 先将下一步的要访问的节点放到对列中
    addNextWords(beginWord, wordDict, toVisit);
    // 这里求的是路径的长度，而不是变换的次数，因此应该从2开始
    int dist = 2;
    // 开始逐层访问
    while (!toVisit.empty()) {
        // 当前曾的元素个数。这是个很有意思的方法，以前做分层遍历树的时候，还得用两个
        // 对列来回捣腾，却没想到用这种方法！！！学习吧，少年
        int num = toVisit.size();
        // 访问当前层的相邻节点，并继续处理
        for (int i = 0; i < num; i++) {
            string word = toVisit.front();
            toVisit.pop();
            // 如果等于结束节点，说明找到路径了，返回
            if (word == endWord) {
                return dist;
            }
            // 继续处理相邻节点的相邻节点
            addNextWords(word, wordDict, toVisit);
        }
        dist++;
    }
    // 没有找到
    return 0;
}

/** ===================== BFS solution over ============================= */



/** ===================== two-end BFS solution ============================= */

// two-end BFS, 据说性能相对单向的BFS会有一定提升，但是还是通不过OJ...
//
// 理解了这个算法，对性能的影响确实只能说是少量的影响。基本思路是：在BFS的过程中，每次从
// 较少的一层节点从较多的一层节点递进，直到首尾相遇。这可能在某些情况下对性能有一点提升，
// 但是并不是数量级的提升。不知道有没有对应的数学证明或者分析

// 主体在这个函数里。每次BFS搜索过程，我们搜索words的相邻节点，直到遇到words2。还是比较容易理解的
int ladderLengthHelper(vector<string> &words1, vector<string> &words2, vector<string> &dict, int level) {
    // 如果一方为空，搜索中断了
    if (words1.empty())
        return 0;
    // 按照大小替换，这是关键部分，这保证每次我们从较少的节点那一层开始递进
    if (words1.size() > words2.size())
        return ladderLengthHelper(words2, words1, dict, level);
    // words3存储下一层相邻节点
    vector<string> words3;
    vector<string>::iterator it;
    vector<string>::iterator it2;
    // 这里的逻辑参考BFS，原理上是一样的
    for (it = words1.begin(); it != words1.end(); ++it) {
        string word = *it;
        for (string::iterator ch = word.begin(); ch != word.end(); ++ch) {
            char tmp = *ch;
            for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                if (*ch != tmp)
                    if (find(words2.begin(), words2.end(), word) != words2.end())
                        return level + 1;
                    else if ((it2 = find(dict.begin(), dict.end(), word)) != dict.end()) {
                        dict.erase(it2);
                        words3.push_back(word);
                    }
            *ch = tmp;
        }
    }
    // 继续下一层遍历
    return ladderLengthHelper(words2, words3, dict, level + 1);
}

int ladderLengthTwoEndBFS(string beginWord, string endWord, vector<string> &dict) {
    // 开始和结束相同，路径中只有一个字符串，返回1
    if (beginWord == endWord)
        return 1;
    vector<string> words1, words2;
    words1.push_back(beginWord);
    words2.push_back(endWord);
    vector<string>::iterator it = find(dict.begin(), dict.end(), beginWord);
    // 从词典中删除开始字符串
    if (it != dict.end()) {
        dict.erase(it);
    }
    // 从词典中删除结束字符串
    it = find(dict.begin(), dict.end(), endWord);
    if (it != dict.end()) {
        dict.erase(it);
    } else {
        // 如果结束字符串不在词典中，肯定找不到，返回0
        return 0;
    }
    return ladderLengthHelper(words1, words2, dict, 1);
}

/** ===================== two-end BFS solution over ============================= */

/** ===================== two-end BFS with map dict solution ============================= */

// 和two-end BFS的思路相同，唯一区别是使用map来作为dict，能提升每次超找的性能。终于通过OJ了!!!!

int ladderLengthHelper2(vector<string> &words1, vector<string> &words2, map<string, bool> &dict, int level) {
    // 如果一方为空，搜索中断了
    if (words1.empty())
        return 0;
    // 按照大小替换，这是关键部分，这保证每次我们从较少的节点那一层开始递进
    if (words1.size() > words2.size())
        return ladderLengthHelper2(words2, words1, dict, level);
    // words3存储下一层相邻节点
    vector<string> words3;
    vector<string>::iterator it;
    map<string, bool>::iterator it2;
    // 这里的逻辑参考BFS，原理上是一样的
    for (it = words1.begin(); it != words1.end(); ++it) {
        string word = *it;
        for (string::iterator ch = word.begin(); ch != word.end(); ++ch) {
            char tmp = *ch;
            for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                if (*ch != tmp)
                    if (find(words2.begin(), words2.end(), word) != words2.end())
                        return level + 1;
                    else if ((it2 = dict.find(word)) != dict.end()) {
                        dict.erase(it2);
                        words3.push_back(word);
                    }
            *ch = tmp;
        }
    }
    // 继续下一层遍历
    return ladderLengthHelper2(words2, words3, dict, level + 1);
}

int ladderLengthTwoEndBFSWithMapDict(string beginWord, string endWord, vector<string> &dict) {
    // 开始和结束相同，路径中只有一个字符串，返回1
    if (beginWord == endWord)
        return 1;
    vector<string> words1, words2;
    words1.push_back(beginWord);
    words2.push_back(endWord);
    vector<string>::iterator it = find(dict.begin(), dict.end(), beginWord);
    // 从词典中删除开始字符串
    if (it != dict.end()) {
        dict.erase(it);
    }
    // 从词典中删除结束字符串
    it = find(dict.begin(), dict.end(), endWord);
    if (it != dict.end()) {
        dict.erase(it);
    } else {
        // 如果结束字符串不在词典中，肯定找不到，返回0
        return 0;
    }
    // 将数组的词典转为map
    map<string, bool> m;
    for (int i=0; i < dict.size(); i++) {
        m[dict[i]] = true;
    }
    return ladderLengthHelper2(words1, words2, m, 1);
}

/** ===================== two-end BFS with map dict solution over ============================= */

int main() {
    //string a[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    //string a[] = {"hot", "dot", "dog", "lot", "log"};
    string a[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    vector<string> input(a, a+sizeof(a)/sizeof(a[0]));

    //cout << ladderLength("hit", "cog", input) << endl;;
    cout << ladderLengthTwoEndBFSWithMapDict("qa", "sq", input) << endl;;
}
