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

/** ====================== dynamic programming solution =============================== */

/**
 * 逐行处理矩阵，针对当前行的每一列，计算以当前行为底边、包含当前点的矩阵的面积。
 * 计算面积需要知道子矩阵的左边界、右边界以及子矩阵的高，按照如下来计算：
 *
 * 1. left[i,j] = max(left[i-1,j], current_left), 其中current_left表示在当前行中matrix中为1的左边界，当然是和matrix[i,j]连续的左边界
 * 2. right[i,j] = min(right[i-1,j], current_right)，其中current_right表示在当前行中matrix为1的右边界，当然是和matrix[i,j]连续的右边界
 * 3. height[i,j] = matrix[i,j] == 1 ? height[i-1,j]+1 : 0。如果当前点为1，则高度为上一行当前列高度+1，否则高度为零。
 *
 * 这样，由于由之前的结果可以计算当前结果，问题变为一个动态规划问题，问题的时间复杂度为O(mn)，空间复杂度为O(n)，在任意时刻只需要记录
 * n个left, right, height值，这n个数据包含上一行以及当前行的。NOTICE 注意这种减少空间使用的方法
 *
 * 问题：当别人提出这种思路的时候，貌似是可以理解的，即使有一些疑问，也可以通过验证，证明这种解法能够覆盖所有的情况，
 * 保证结果是无误的。问题是如何自己想出类似的解法呢？这貌似需要比较深入的数学知识，才能针对问题建模，再进行证明。
 * 先不强求能自己提出吧，尽量好好理解，至少遇到类似问题的时候可以解决。
 */
int maximalRectangleWithDP(vector<vector<char> >& matrix) {
    int m = matrix.size();
    if (m == 0) {
        return 0;
    }
    int n = matrix[0].size();
    int maxA = 0;
    vector<int> left(n, 0), right(n, n), height(n, 0);
    for (int i=0; i < m; i++) {
        // 用两个变量来记录左边界和右边界
        int current_left = 0, current_right = n;

        // 计算当前行的height值，可以向前或者向后计算
        for (int j=0; j < n; j++) {
            height[j] = matrix[i][j] == '1' ? height[j]+1 : 0;
        }

        // 计算当前行的left值，注意在计算过程中更新current_left的值，以及引用上
        // 一行的left结果。这里将两行的结果压缩放到left中存储。这里的计算必须是
        // 从左向右的
        for (int j=0; j < n; j++) {
            if (matrix[i][j] == '1') {
                left[j] = max(left[j], current_left);
            } else {
                left[j] = 0;
                current_left = j+1;
            }
        }

        // 计算当前行的right值，和left类似，注意的是把max换成min，以及默认是n，
        // 从右向左计算
        for (int j=n-1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                right[j] = min(right[j], current_right);
            } else {
                right[j] = n;
                current_right = j;
            }
        }

        // left/right/height都计算好了，现在可以开始计算面积了。在
        // 计算的过程中记录最大面积
        for (int j=0; j < n; j++) {
            int area = (right[j] - left[j]) * height[j];
            if (area > maxA) {
                maxA = area;
            }
        }
    }
    return maxA;
}

/** ====================== dynamic programming solution over =============================== */


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

/** =========================== naive solution over ======================================= */

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
    //cout << maximalRectangle(input) << endl;
    cout << maximalRectangleWithDP(input) << endl;
}
