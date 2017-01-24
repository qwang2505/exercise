#include "../include.h"

/**
 * Given a m x n grid filled with non-negative numbers, find a path 
 * from top left to bottom right which minimizes the sum of all numbers 
 * along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */

int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();

    vector<vector<int> > sums(m, vector<int>(n, 0));
    sums[0][0] = grid[0][0];
    for (int i=1; i < m; i++) {
        sums[i][0] = grid[i][0] + sums[i-1][0];
    }
    for (int j=1; j < n; j++) {
        sums[0][j] = grid[0][j] + sums[0][j-1];
    }

    for (int i=1; i < m; i++) {
        for (int j=1; j < n; j++) {
            sums[i][j] = min(sums[i-1][j], sums[i][j-1]) + grid[i][j];
        }
    }
    return sums[m-1][n-1];
}

int main(int argc, char** argv) {
    vector<vector<int> > input(3, vector<int>(3, 1));
    input[1][1] = 2;
    input[2][1] = 3;
    input[0][2] = 10;
    input[2][0] = 10;
    printVector(input);

    cout << minPathSum(input) << endl;
}
