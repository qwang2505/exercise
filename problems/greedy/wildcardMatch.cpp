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
        return match(s, p.substr(1));
    }
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
    char c = s[0];
    char p0 = p[0];
    switch (p0) {
        case '?':
            return match(s.substr(1), p.substr(1));
        case '*':
            return matchStar(s, p);
        default:
            if (c == p0) {
                return match(s.substr(1), p.substr(1));
            } else {
                return false;
            }
    }
    return false;

}
/** 我的解法结束 **/

// TODO 理解其他的解法，好好理解，背诵，深刻理解
bool isMatch(string s, string p) {
    // 我的解法，超出运行时间要求。应该是最容易想到、最简便的解法，
    // 回溯算法来解，所以时间复杂度超高
    return match(s, p);
}

int main(int argc, char** argv) {
    cout << (isMatch("aa", "a") == false) << endl;
    cout << (isMatch("aa", "aa") == true) << endl;
    cout << (isMatch("aaa", "aa") == false) << endl;
    cout << isMatch("aa", "*") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", "?*") << endl;
    cout << (isMatch("aab", "c*a*b") == false) << endl;
    cout << (isMatch("aab", "a*c") == false) << endl;
    cout << (isMatch("aab", "a**ab") == true) << endl;
    cout << isMatch("", "*") << endl;
    cout << isMatch("ba", "*a*") << endl;
    cout << (isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") == false) << endl;
}
