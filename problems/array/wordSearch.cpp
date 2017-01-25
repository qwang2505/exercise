#include "../include.h"

/**
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

bool found(vector<vector<char> >& board, int i, int j, string word, int m, int n, vector<vector<bool> >& searchMap) {
    if (word.length() == 0) {
        return true;
    // 使用searchMap保证不要重复走走过的路径
    } else if (searchMap[i][j]) {
        return false;
    } else if (board[i][j] != word[0]) {
        return false;
    // 注意处理一个字符的情况，没有上下左右邻居
    } else if (word.length() == 1) {
        return true;
    }
    searchMap[i][j] = true;
    if (i > 0 && found(board, i-1, j, word.substr(1), m, n, searchMap)) {
        return true;
    } else if (j > 0 && found(board, i, j-1, word.substr(1), m, n, searchMap)) {
        return true;
    } else if (i < m-1 && found(board, i+1, j, word.substr(1), m, n, searchMap)) {
        return true;
    } else if (j < n-1 && found(board, i, j+1, word.substr(1), m, n, searchMap)) {
        return true;
    }
    // 没找到就把searchMap重置
    searchMap[i][j] = false;
    return false;

}

bool exist(vector<vector<char> >& board, string word) {
    int m = board.size();
    if (m == 0) {
        return false;
    }
    int n = board[0].size();

    vector<vector<bool> > searchMap(m, vector<bool>(n, false));
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (found(board, i, j, word, m, n, searchMap)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    //vector<vector<char> > input(3, vector<char>(4));
    vector<vector<char> > input(1, vector<char>(1));
    input[0][0] = 'A';
    /*
    input[0][1] = 'B';
    input[0][2] = 'C';
    input[0][3] = 'E';
    input[1][0] = 'S';
    input[1][1] = 'F';
    input[1][2] = 'C';
    input[1][3] = 'S';
    input[2][0] = 'A';
    input[2][1] = 'D';
    input[2][2] = 'E';
    input[2][3] = 'E';
    */
    cout << exist(input, "ABCCED") << endl;
    cout << exist(input, "SEE") << endl;
    cout << exist(input, "ABCB") << endl;
    cout << exist(input, "A") << endl;
}
