#include "../include.h"

/**
 * Given n non-negative integers representing the histogram's bar height where the 
 * width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 */

/** ========================= divide and conquer ======================================== */

/**
 * 使用divide and conquer的解法来解决这个问题，整体思路还是比较容易理解的，难点在于
 * 如何在log(n)的时间内求指定区间的最小值及其在input中的索引，使用segment tree可以
 * 解。
 *
 * 注意：这种解法通不过leetcode，大概是因为占用了一些额外空间的缘故
 */

// 又笨了一下，实际上在segment tree中只需要存储索引就可以了，value可以通过输入数组
// 加上索引获取到，就不用这么麻烦了。改为直接存储索引，但是保留这个结构体，以后续反省
struct Node {
    // 节点的值
    int v;
    // 节点值对应的索引
    int i;

    Node(int value, int index) {
        v = value;
        i = index;
    }
};

// 递归构建segment tree
int constructSTUtil(vector<int>& input, vector<int>& st, int start, int end, int current) {
    if (start == end) {
        st[current] = start;
        return st[current];
    }
    int mid = (start + end) / 2;
    int left = constructSTUtil(input, st, start, mid, 2*current+1);
    int right = constructSTUtil(input, st, mid+1, end, 2*current+2);
    st[current] = input[left] < input[right] ? left : right;
    return st[current];
}

// 为输入数组构建segment tree用于计算指定区间的最小值，树的每个节点包含区间最小值，
// 以及最小值在输入数组中的索引
vector<int> constructST(vector<int>& input) {
    int n = input.size();
    int h = ceil(log2(n));
    int nodesCount = 2 * (int)pow(2, h) - 1;
    vector<int> st(nodesCount, 0);
    constructSTUtil(input, st, 0, n-1, 0);
    return st;
}

int rangeMin(vector<int>& st, vector<int>& input, int start, int end, int qstart, int qend, int current) {
    if (qstart <= start && qend >= end) {
        return st[current];
    }
    if (start > qend || end < qstart) {
        return numeric_limits<int>::max();
    }
    int mid = (start + end) / 2;
    int left = rangeMin(st, input, start, mid, qstart, qend, 2*current+1);
    int right = rangeMin(st, input, mid+1, end, qstart, qend, 2*current+2);
    if (left >= 0 && left < input.size() && right >= 0 && right < input.size()) {
        return input[left] < input[right] ? left : right;
    } else if (left >= 0 && left < input.size()) {
        return left;
    } else {
        return right;
    }
}

int largestRectangleAreaWithDCUtil(vector<int>& st, vector<int>& input, int start, int end) {
    if (start > end) {
        return 0;
    }
    if (start == end) {
        return input[start];
    }
    int n = input.size();
    int mid = rangeMin(st, input, 0, n-1, start, end, 0);
    if (mid < 0 || mid >= input.size()) {
        return 0;
    }
    int left = largestRectangleAreaWithDCUtil(st, input, start, mid-1);
    int right = largestRectangleAreaWithDCUtil(st, input, mid+1, end);
    int area = (end - start + 1) * input[mid];
    return (left > right) ? (left > area ? left : area) : (right > area ? right : area);
}

int largestRectangleAreaWithDC(vector<int>& heights) {
    // 构建segment tree，用于后面求区间内的最小值
    vector<int> st = constructST(heights);
    return largestRectangleAreaWithDCUtil(st, heights, 0, heights.size()-1);
}

/** ========================= divide and conquer over ======================================== */


/** ========================= dynamic programming ======================================== */

struct Info {
    int area;
    int start;
    int min;
    Info(int start, int min, int area) {
        this->area = area;
        this->start = start;
        this->min = min;
    }
};

// 错误解法，用的是动态规划，对于[1,2,3,4,5]这个输入会产生错误的输出。原因是这里的状态转移中
// 最优解不一定能从上一次的最优解中得到
int largestRectangleAreaWithDP(vector<int>& heights) {
    if (heights.size() < 1) {
        return 0;
    }
    vector<Info> dp(heights.size(), Info(0, 0, 0));
    dp[0].start = 0;
    dp[0].min = heights[0];
    dp[0].area = heights[0];
    int max = heights[0];
    for (int i=1; i < heights.size(); i++) {
        int area, min, start;
        if (heights[i] >= dp[i-1].min) {
            area = dp[i-1].area + dp[i-1].min;
        } else {
            int diff = dp[i-1].min - heights[i];
            area = dp[i-1].area - (i - dp[i-1].start) * diff + heights[i];
        }
        if (area > heights[i]) {
            dp[i].area = area;
            dp[i].min = dp[i-1].min < heights[i] ? dp[i-1].min : heights[i];
            dp[i].start = dp[i-1].start;
        } else {
            dp[i].area = heights[i];
            dp[i].min = heights[i];
            dp[i].start = i;
        }
        if (dp[i].area > max) {
            max = dp[i].area;
        }
    }
    return max;
}

/** ========================= dynamic programming over ======================================== */


/** ========================= stack ======================================== */

// 太诡异了，不好理解，需要多看多想
int largestRectangleAreaWithStack(vector<int>& heights) {
    if (heights.size() == 0) {
        return 0;
    }
    vector<int> stack;
    int max = 0;
    int i = 0;
    int n = heights.size();
    while (i < n) {
        if (stack.empty() || heights[i] >= heights[stack.back()]) {
            stack.push_back(i++);
        } else {
            int j = stack.back();
            stack.pop_back();
            int area = heights[j] * (stack.empty() ? i : i - stack.back() - 1);
            if (area > max) {
                max = area;
            }
        }
    }
    while (stack.size() > 0) {
        int tp = stack.back();
        stack.pop_back();
        int area = heights[tp] * (stack.empty() ? i : i - stack.back() - 1);
        if (area > max) {
            max = area;
        }
    }
    return max;
}

/** ========================= stack over ======================================== */

int main(int argc, char** argv) {
    int a[] = {2,1,5,6,2,3};
    //int a[] = {2,1,2};
    //int a[] = {6,1,5,4,5,2,6};
    //int a[] = {1,2,3,4,5};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    //cout << largestRectangleArea(input) << endl;
    //cout << largestRectangleAreaWithDC(input) << endl;
    cout << largestRectangleAreaWithStack(input) << endl;
}
