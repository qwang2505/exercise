#include "../include.h"

/**
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * Return
 *   [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *   ]
 *
 * Note:
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 */

/** ===================== two-end BFS with map dict solution ============================= */

// 参考wordLadder中的解法，实际上有多种解法，但是这种是最高效的，因此在这里只改动这种来解决问题
// 个人感觉，不用two-end的BFS，只用普通的BFS应该也能通过OJ
//
// 需要注意的是在BFS中如何记录路径。在BFS中记录路径不向DFS那么容易，需要额外的空间来做处理。好好记住

// 递归获取路径，nexts中记录的是某个节点的相邻节点，逐层向下就可以得到从start到end的路径
void getPath(string beginWord, string &endWord, map<string, vector<string> > &nexts,
    vector<string> &path, vector<vector<string> > &paths) {
    if (beginWord == endWord)
        paths.push_back(path);
    else
        for (vector<string>::iterator it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
            path.push_back(*it);
            getPath(*it, endWord, nexts, path, paths);
            path.pop_back();
        }
}

bool findLaddersHelper(map<string, bool> &words1, map<string, bool> &words2, map<string, bool> &dict, 
        map<string, vector<string> > &nexts, bool &words1IsBegin) {
    // 这个变量用于记录当前的words是不是正向搜索，用于将路径记录到nexts中。如果当前是逆向搜索，
    // 应该反过来记录到nexts中
    words1IsBegin = !words1IsBegin;

    // 如果一个为空，搜索中断了
    if (words1.empty())
        return false;

    // 翻转，从较小的一层开始递进
    if (words1.size() > words2.size())
        return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);

    // TODO 这里为什么要额外删除，而不是在搜索的过程中直接删除呢？
    // 在wordLadder中可以直接在搜索中删除，但是这里如果在搜索中删除的话，会有一些路径丢失
    // 如果不能理解，那就牢牢记住吧
    for (map<string, bool>::iterator it = words1.begin(); it != words1.end(); ++it)
        dict.erase(it->first);
    for (map<string, bool>::iterator it = words2.begin(); it != words2.end(); ++it)
        dict.erase(it->first);

    // 下面的过程和wordLadder类似，唯一的区别是需要记录nexts
    map<string, bool> words3;
    bool reach = false;
    for (map<string, bool>::iterator it = words1.begin(); it != words1.end(); ++it) {
        string word = it->first;
        for (string::iterator ch = word.begin(); ch != word.end(); ++ch) {
            char tmp = *ch;
            for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                if (*ch != tmp)
                    if (words2.find(word) != words2.end()) {
                        reach = true;
                        // 记录单词的相邻单词，需要知道当前的遍历是前向的还是后向的
                        words1IsBegin ? nexts[it->first].push_back(word) : nexts[word].push_back(it->first);
                    }
                    else if (!reach && dict.find(word) != dict.end()) {
                        words3[word] = true;
                        // 记录单词的相邻单词，需要知道当前的遍历是前向的还是后向的
                        words1IsBegin ? nexts[it->first].push_back(word) : nexts[word].push_back(it->first);
                    }
            *ch = tmp;
        }
    }
    // 如果搜索成功就直接返回true，否则继续搜索
    return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
}

vector<vector<string> > findLaddersTwoEndBFSWithMapDict(string beginWord, string endWord, vector<string> &dict) {
    vector<vector<string> > paths;
    vector<string> path(1, beginWord);
    if (beginWord == endWord) {
        paths.push_back(path);
        return paths;
    }
    if (find(dict.begin(), dict.end(), endWord) == dict.end()) {
        return paths;
    }
    map<string, bool> words1, words2;
    words1[beginWord] = true;
    words2[endWord] = true;
    map<string, vector<string> > nexts;
    bool words1IsBegin = false;
    // 把输入的词典数组转换为map，提升查找的效率
    map<string, bool> m;
    for (int i=0; i < dict.size(); i++) {
        if (dict[i] != beginWord && dict[i] != endWord) {
            m[dict[i]] = true;
        }
    }

    if (findLaddersHelper(words1, words2, m, nexts, words1IsBegin)) {
        getPath(beginWord, endWord, nexts, path, paths);
    }

    return paths;
}

/** ===================== two-end BFS with map dict solution over ============================= */


/** ======================== naive solution ============================ */

// 检测两个字符串是否能变换，也就是两个字符串的编辑距离是否为1
// 这里限制两个字符串的长度是相等的
bool changeable(string a, string b) {
    int n = a.length();
    if (n != b.length()) {
        return false;
    }
    int c = 0;
    for (int i=0; i < n; i++) {
        if (a[i] != b[i]) {
            c += 1;
        }
        if (c > 1) {
            return false;
        }
    }
    return c == 1;
}

// 构建变换矩阵，对wordList中的字符串两两比较进行处理，将结果存储在
// 矩阵中，表示位置i和位置j的两个字符串是否是可以变换的
vector<vector<bool> > buildOld(vector<string>& wordList) {
    vector<vector<bool> > distMatrix(wordList.size(), vector<bool>(wordList.size(), false));
    for (int i=0; i < wordList.size(); i++) {
        for (int j=i; j < wordList.size(); j++) {
            if (changeable(wordList[i], wordList[j]) == 1) {
                distMatrix[i][j] = distMatrix[j][i] = true;
            }
        }
    }
    return distMatrix;
}

// 改进：使用map来存储每个word可以有哪些变换后的word，这样就不用再查询了
map<int, vector<int> > build(vector<string>& wordList) {
    map<int, vector<int> > m;
    for (int i=0; i < wordList.size(); i++) {
        for (int j=i; j < wordList.size(); j++) {
            if (changeable(wordList[i], wordList[j]) == 1) {
                // 加入到map中，记录每个字符串可以变换为哪些字符串
                m[i].push_back(j);
                m[j].push_back(i);
            }
        }
    }
    return m;
}

// 查找辅助函数，递归查找
void findHelper(int index, string end, map<int, vector<int> >& wordMap, vector<string>& aux, vector<vector<string> >& output, 
        vector<bool>& found, vector<string>& wordList, int& minLen) {
    // 如果当前字符串等于结果，说明查找成功，将结果保存
    if (wordList[index] == end) {
        output.push_back(aux);
        if (aux.size() < minLen) {
            minLen = aux.size();
        }
        return;
    }

    // 超过已有的最短长度，并且没有结束，不需要再递归求解了
    if (aux.size() >= minLen) {
        return;
    }

    // 查找，首先找到当前与当前字符串编辑距离为1的其他字符串，再递归处理
    for (int i=0; i < wordMap[index].size(); i++) {
        int j = wordMap[index][i];
        if (found[j]) {
            continue;
        }
        // 标示已经查找过，避免重复路径
        found[j] = true;
        // 将结果放到临时的结果存储中
        aux.push_back(wordList[j]);
        // 递归查找
        findHelper(j, end, wordMap, aux, output, found, wordList, minLen);
        // 从临时结果中删除
        aux.pop_back();
        // 将路径删除
        found[j] = false;
    }
}

// 朴素想法，基本思路是递归，从开始字符串开始，分别处理每隔字符串，
// 寻找编辑距离为1的下一个字符串，再递归处理，直到找到要查找的字符串
//
// 问题：有一些重复计算的内容，且题目要求是只返回最短路径，在这里的计算中会将
// 所有路径都查找出来，然后再进行过滤。
vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string> > output;
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
        return output;
    }
    // 用来指示两个字符串是否是可以变换的
    map<int, vector<int> > wordMap = build(wordList);

    vector<bool> found(wordList.size(), false);

    vector<string> aux;
    aux.push_back(beginWord);

    int minLen = numeric_limits<int>::max();

    for (int i=0; i < wordList.size(); i++) {
        if (changeable(beginWord, wordList[i])) {
            found[i] = true;
            aux.push_back(wordList[i]);
            findHelper(i, endWord, wordMap, aux, output, found, wordList, minLen);
            aux.pop_back();
            found[i] = false;
        }
    }

    if (output.size() == 0) {
        return output;
    }

    // 去掉非最短路径的结果
    int m = numeric_limits<int>::max();
    for (int i=0; i < output.size(); i++) {
        if (output[i].size() < m) {
            m = output[i].size();
        }
    }

    vector<vector<string> >::iterator it = output.begin();
    for (; it != output.end(); ) {
        if ((*it).size() > m) {
            output.erase(it);
        } else {
            ++it;
        }
    }

    return output;
}

/** ======================== naive solution over ============================ */

int main() {
    //string a[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    string a[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    vector<string> input(a, a+sizeof(a)/sizeof(a[0]));

    //vector<vector<string> > output = findLadders("hit", "cog", input);
    vector<vector<string> > output = findLaddersTwoEndBFSWithMapDict("qa", "sq", input);
    printVector(output);
}
