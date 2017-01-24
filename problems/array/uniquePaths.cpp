#include "../include.h"

/**
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 */

// 递归解法，时间复杂度比较高，有很多重复计算。一般这样的问题，如果想要提高时间复杂度，采用bottom-up
// 是一种比较好的方法，避免了重复计算
int paths(int i, int j, int m, int n, vector<vector<int> >& dp) {
    if (i == m-1 && j == n-1) {
        dp[i][j] = 1;
        return 1;
    }
    if (dp[i][j] > 0) {
        return dp[i][j];
    }
    int count = 0;
    if (i < m - 1) {
        count += paths(i+1, j, m, n, dp);
    }
    if (j < n - 1) {
        count += paths(i, j+1, m, n, dp);
    }
    dp[i][j] = count;
    return count;
}

// 使用动态规划，实际上和递归解法完全一样，只是换个角度来计算，很聪明的想法
int dp(int m, int n) {
    // 初始化为1，至少有一个路径
    vector<vector<int> > dp(m, vector<int>(n, 1));
    // 将原来的只能向右/向下移动，从开头到结尾换一个角度来考虑
    for (int i=1; i < m; i++) {
        for (int j=1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int uniquePaths(int m, int n) {
    // 以下是第一种解法，用递归，使用缓存来避免重复计算
    /*
    if (m == 0 || n == 0) {
        return 1;
    }
    vector<vector<int> > dp(m, vector<int>(n, 0));
    return paths(0, 0, m, n, dp);
    */

    // 以下是第二种解法
    return dp(m, n);
}

int main(int argc, char** argv) {
    cout << uniquePaths(2, 2) << endl;
    cout << uniquePaths(3, 7) << endl;
}
