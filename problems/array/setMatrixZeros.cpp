#include "../include.h"

/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 * click to show follow up.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

void setZeroes(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if (m == 0) {
        return;
    }
    int n = matrix[0].size();
    int last_0_row = -1;
    for (int i=m-1; i >= 0; i--) {
        for (int j=0; j < n; j++) {
            if (matrix[i][j] == 0) {
                last_0_row = i;
                break;
            }
        }
        if (last_0_row != -1) {
            break;
        }
    }
    if (last_0_row == -1) {
        return;
    }

    for (int i=0; i < last_0_row; i++) {
        for (int j=0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[last_0_row][j] = 0;
            }
        }
    }

    for (int i=0; i < last_0_row; i++) {
        bool zero = false;
        for (int j=0; j < n; j++) {
            if (matrix[i][j] == 0) {
                zero = true;
                break;
            }
        }
        if (zero) {
            for (int j=0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j=0; j < n; j++) {
        if (matrix[last_0_row][j] == 0) {
            for (int i=0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j=0; j < n; j++) {
        matrix[last_0_row][j] = 0;
    }
}

int main(int argc, char** argv) {
    vector<vector<int> > input(4, vector<int>(5, 1));
    input[0][1] = 0;
    //input[0][4] = 0;
    input[2][1] = 0;
    input[2][3] = 0;
    input[3][4] = 0;
    printVector(input);
    setZeroes(input);
    printVector(input);
}
