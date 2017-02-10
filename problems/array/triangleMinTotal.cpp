#include "../include.h"

/**
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *     [2],
 *    [3,4],
 *   [6,5,7],
 *  [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

/** ==================== naive solution =========================== */

// 没有什么特别的解法，分析问题后，使用一个辅助数组aux记录从第一层开始累加的结果，
// 最后找出最小值就可以了。需要注意的是在更新aux的过程中要从后向前更新，否则先更新
// 的结果会覆盖上一行的结果，造成结果错误。
int minimumTotal(vector<vector<int> >& triangle) {
    int n = triangle.size();
    if (n == 0) {
        return 0;
    }
    vector<int> aux(n, 0);
    int minV = numeric_limits<int>::max();
    for (int i=0; i < n; i++) {
        // 注意从后向前更新aux的值，因为会覆盖之前的值
        for (int j=i; j >= 0; j--) {
            if (j == 0) {
                aux[j] += triangle[i][0];
            } else if (j == i) {
                aux[j] = aux[j-1] + triangle[i][j];
            } else {
                aux[j] = triangle[i][j] + min(aux[j], aux[j-1]);
            }
            if (i == n-1 && aux[j] < minV) {
                minV = aux[j];
            }
        }
    }
    return minV;
}

/** ==================== naive solution over =========================== */

int main() {
    int rows[][4] = {
        {2,0,0,0},
        {3,4,0,0},
        {6,5,7,0},
        {4,1,8,3}
    };
    vector<vector<int> > input;
    for (int i=0; i < 4; i++) {
        input.push_back(vector<int>(rows[i], rows[i]+sizeof(rows[i][0])));
    }
    cout << minimumTotal(input) << endl;
}
