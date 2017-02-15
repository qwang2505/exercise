#include "../include.h"

/**
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */

/** 以下是我的解法，没有通过测试，原因是运行时间超出限制 **/
bool match(string s, string p);

bool matchStar(string s, string p) {
    int sl = s.length();
    if (sl == 0) {
        // 处理字符串长度已经为0的情况
        return match(s, p.substr(1));
    }
    // 循环，假设星号分别匹配i个字符，看是否match
    // 这里性能太差了
    for (int i=0; i < sl+1; i++) {
        bool r = match(s.substr(i), p.substr(1));
        if (r) {
            return r;
        }
    }
    return false;
}

bool match(string s, string p) {
    if (s.length() == 0 && p.length() == 0) {
        return true;
    } else if (p.length() == 0) {
        return false;
    } else if (s.length() == 0) {
        bool allStar = true;
        for (int i=0; i < p.length(); i++) {
            if (p[i] != '*') {
                allStar = false;
                break;
            }
        }
        return allStar;
    }
    // 拿出第一个字符
    char c = s[0];
    char p0 = p[0];
    switch (p0) {
        case '?':
            // 问好匹配任何字符，所以从下一个字符开始继续匹配
            return match(s.substr(1), p.substr(1));
        case '*':
            // 星号特殊处理
            return matchStar(s, p);
        default:
            // 符号相同，继续匹配
            if (c == p0) {
                return match(s.substr(1), p.substr(1));
            } else {
                // 否则，绝对不匹配
                return false;
            }
    }
    return false;

}
/** 我的解法结束 **/

/** ========================= iteration method ======================= */

bool isMatchLoop(string s, string p) {
    int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

    // 为什么不怕j越界呢
    for(i=0,j=0 ; i<slen; ++i, ++j)
    {
        if(p[j]=='*')
        {
            // 遇到星号了，记录遇到星号时i，j的情况，用于将来进行回溯
            iStar = i;
            jStar = j;
            --i;
        }
        else
        { 
            if(p[j]!=s[i] && p[j]!='?')
            {
                // 没匹配到，看能不能回溯
                if(iStar >=0)
                {
                    // 遇到过星号，回溯到上一个星号的位置。这里不需要将i赋值为iStar+1，因为循环会对i+1
                    i = iStar++;
                    j = jStar;
                }
                // 匹配失败，也没遇到星号，一切都结束了
                else return false;
            }
        }
    }
    while(p[j]=='*') ++j;
    return j==plen;
}

/** ========================= iteration method over ======================= */

// TODO 理解其他的解法，好好理解，背诵，深刻理解
bool isMatch(string s, string p) {
    // 我的解法，超出运行时间要求。应该是最容易想到、最简便的解法，
    // 回溯算法来解，所以时间复杂度超高
    //return match(s, p);
    return isMatchLoop(s, p);
}

int main(int argc, char** argv) {
    /*cout << (isMatch("aa", "a") == false) << endl;
    cout << (isMatch("aa", "aa") == true) << endl;
    cout << (isMatch("aaa", "aa") == false) << endl;
    */
    cout << (isMatch("aaaa", "aa") == false) << endl;
    /*
    cout << isMatch("aaaa", "a*a") << endl;
    cout << isMatch("aa", "*") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", "?*") << endl;
    cout << (isMatch("aab", "c*a*b") == false) << endl;
    cout << (isMatch("aab", "a*c") == false) << endl;
    cout << (isMatch("aab", "a**ab") == true) << endl;
    cout << isMatch("", "*") << endl;
    cout << isMatch("ba", "*a*") << endl;
    cout << (isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") == false) << endl;
    */
}
