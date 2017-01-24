#include "../include.h"

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
        return false;
    }
    int n = matrix[0].size();
    int low = 0, high = m * n - 1, mid;
    int i, j;
    while (low <= high) {
        mid = (low + high) / 2;
        i = mid / n;
        j = mid - i * n;
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    vector<vector<int> > input(3, vector<int>(3, 0));
    input[0][0] = 1;
    input[0][1] = 3;
    input[0][2] = 5;
    input[0][3] = 7;
    input[1][0] = 10;
    input[1][1] = 11;
    input[1][2] = 16;
    input[1][3] = 20;
    input[2][0] = 23;
    input[2][1] = 30;
    input[2][2] = 34;
    input[2][3] = 50;
    cout << searchMatrix(input, 3) << endl;
}
