#include "../include.h"

/**
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */

// 记住这种解法，挺有意思
void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    if (n <= 1 || matrix[0].size() != n) {
        return;
    }
    for (int i=0; i < n; i++) {
        for (int j=0; j < i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i=0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotate2(vector<vector<int> >& matrix) {
    int n = matrix.size();
    if (n <= 1 || matrix[0].size() != n) {
        return;
    }
    vector<vector<int> > aux(n, vector<int>(n, 0));

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            aux[j][n-i-1] = matrix[i][j];
        }
    }
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            matrix[i][j] = aux[i][j];
        }
    }
}

int main(int argc, char** argv) {
    vector<vector<int> > input;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row1.push_back(4);
    input.push_back(row1);
    vector<int> row2;
    row2.push_back(5);
    row2.push_back(6);
    row2.push_back(7);
    row2.push_back(8);
    input.push_back(row2);
    vector<int> row3;
    row3.push_back(9);
    row3.push_back(10);
    row3.push_back(11);
    row3.push_back(12);
    input.push_back(row3);
    vector<int> row4;
    row4.push_back(13);
    row4.push_back(14);
    row4.push_back(15);
    row4.push_back(16);
    input.push_back(row4);

    rotate2(input);
    printVector(input);

    return 0;
}
