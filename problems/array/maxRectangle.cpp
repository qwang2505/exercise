#include "../include.h"

/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 6.
 */

/** =========================== naive solution ======================================= */

// 最直观/简单的解法，时间复杂度O(m2n2)，空间复杂度O(mn)
// 通不过leetcode验证，时间超限
int maximalRectangle(vector<vector<char> >& matrix) {
    int m = matrix.size();
    if (m == 0) {
        return 0;
    }
    int n = matrix[0].size();
    int max = 0;
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (matrix[i][j] == '0') {
                continue;
            }
            vector<vector<bool> > aux = vector<vector<bool> >(m, vector<bool>(n, false));
            for (int k=i; k < m; k++) {
                for (int l=j; l < n; l++) {
                    if (k == i && l == j) {
                        aux[k][l] = matrix[i][j] == '1';
                    } else if (matrix[k][l] == '1'){
                        aux[k][l] = (k > i ? aux[k-1][l] : true) && (l > j ? aux[k][l-1] : true);
                    }
                    if (aux[k][l]) {
                        int area = (k-i+1) * (l-j+1);
                        if (area > max) {
                            max = area;
                        }
                    }
                }
            }
        }
    }
    return max;
}

/** =========================== naive solution ======================================= */

int main() {
    char r1[] = {'1', '0', '1', '0', '0'};
    char r2[] = {'1', '0', '1', '1', '1'};
    char r3[] = {'1', '1', '1', '1', '1'};
    char r4[] = {'1', '0', '0', '1', '0'};
    vector<vector<char> > input;
    input.push_back(vector<char>(r1, r1+sizeof(r1)/sizeof(r1[0])));
    input.push_back(vector<char>(r2, r2+sizeof(r2)/sizeof(r2[0])));
    input.push_back(vector<char>(r3, r3+sizeof(r3)/sizeof(r3[0])));
    input.push_back(vector<char>(r4, r4+sizeof(r4)/sizeof(r4[0])));
    cout << maximalRectangle(input) << endl;
}
