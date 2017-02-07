#include "../include.h"

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

// 没什么技巧，一般的思路就能解决，问题是细节以及整体思路
// 以后再解决
vector<int> spiralOrder(vector<vector<int>>& matrix) {
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

    vector<int> output = spiralOrder(input);
    printVector(output);

    return 0;
}
