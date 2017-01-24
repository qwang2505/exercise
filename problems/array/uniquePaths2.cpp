#include "../include.h"

/**
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 *
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) {
        return 0;
    }
    int n = obstacleGrid[0].size();
    bool flag = false;
    for (int i=0; i < m; i++) {
        if (obstacleGrid[i][0] == 1 || flag) {
            obstacleGrid[i][0] = 1;
            flag = true;
        }
    }
    flag = false;
    for (int j=0; j < n; j++) {
        if (obstacleGrid[0][j] == 1 || flag) {
            obstacleGrid[0][j] = 1;
            flag = true;
        }
    }

    // 初始化为1，至少有一个路径
    vector<vector<int> > dp(m, vector<int>(n, 1));
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }
        }
    }
    // 将原来的只能向右/向下移动，从开头到结尾换一个角度来考虑
    for (int i=1; i < m; i++) {
        for (int j=1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(int argc, char** argv) {
    //vector<vector<int> > input(3, vector<int>(3, 0));
    //input[1][1] = 1;

    vector<vector<int> > input(1, vector<int>(2, 0));
    input[0][0] = 1;
    cout << uniquePathsWithObstacles(input) << endl;
}
