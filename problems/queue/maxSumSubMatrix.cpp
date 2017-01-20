#include "../include.h"


/**
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
 *
 * Example:
 * Given matrix = [
 *   [1,  0, 1],
 *   [0, -2, 3]
 * ]
 * k = 2
 * 
 * The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
 */

// 最简单的解法，时间复杂度O(m2n2)，空间复杂度O(mn)
int naiveSolution(vector<vector<int> >& matrix, int k) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int best = numeric_limits<int>::max();
    vector<vector<int> > sums(m);
    for (int i=0; i < m; i++) {
        vector<int> row(n);
        sums[i] = row;
    }
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            // reset sums vector for every start point
            for (int o=0; o < m; o++) {
                for (int l=0; l < n; l++) {
                    sums[o][l] = 0;
                }
            }
            // record sum of every end point in sums
            for (int x=i; x < m; x++) {
                for (int y=j; y < n; y++) {
                    sums[x][y] = matrix[x][y];
                    if (x > 0) {
                        sums[x][y] += sums[x-1][y];
                    }
                    if (y > 0) {
                        sums[x][y] += sums[x][y-1];
                    }
                    if (x > 0 && y > 0) {
                        sums[x][y] -= sums[x-1][y-1];
                    }
                    int sum = sums[x][y];
                    if (sum <= k && k - sum < best) {
                        best = k - sum;
                    }
                }
            }
        }
    }
    return k - best;
}

int betterSolution(vector<vector<int> >& matrix, int k) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int best = numeric_limits<int>::min();
    for (int i=0; i < n; i++) {
        vector<int> rowSum(m, 0);
        for (int j=i; j < n; j++) {
            for (int x=0; x < m; x++) {
                rowSum[x] += matrix[x][j];
            }
            // 这里是有问题的，先把一维的这种问题解决了吧
            // 使用set来解决，方法还是比较巧妙的。
            // 先在cum[i]中记录running sum，也就是c[i]=SUM(c[0], c[1], ..., c[i])
            // 这样的话要求的 cum[j]-cum[i]即为i到j的sum，要求得问题变成了
            // cum[j]-cum[i]<=k && i<j 的最大的cum[j]-cum[i]的值
            int cum = 0;
            int curMax = numeric_limits<int>::min();
            set<int> s;
            // TODO 为什么要加入一个0呢？
            s.insert(0);
            for (int x=0; x < m; x++) {
                cum += rowSum[x];
                set<int>::iterator it = s.lower_bound(cum-k);
                if (it != s.end()) {
                    curMax = max(curMax, cum - *it);
                }
                s.insert(cum);
            }
            best = max(best, curMax);
        }
    }
    return best;
}

int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
    //return naiveSolution(matrix, k);
    return betterSolution(matrix, k);
}

int main(int argc, char** argv) {
    vector<vector<int> > input;
    vector<int> row1;
    row1.push_back(2);
    row1.push_back(2);
    row1.push_back(-1);
    //vector<int> row2;
    //row2.push_back(0);
    //row2.push_back(-2);
    //row2.push_back(3);
    input.push_back(row1);
    //input.push_back(row2);
    cout << maxSumSubmatrix(input, 2) << endl;
}
