#include "../include.h"

/**
 * Let us consider the following problem to understand Segment Trees.
 *
 * We have an array arr[0 . . . n-1]. We should be able to
 * 1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1
 * 2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.
 *
 * 几个重点知识：
 * 1. segment tree的基本思想，需要考虑每个节点中存储什么东西，如何来达到题目要求
 * 2. 如何构造segment tree：一般是递归，bottom-up的方式来构造
 * 3. 如何使用数组表示树：这也是一个重点需要注意的点
 * 4. 如何通过segment tree求解对应的问题
 */

// 求两个索引的中间位置
int getMid(int s, int e) {
    return (s + e) / 2;
}

// 用于递归构造segment tree的工具函数，需要好好看，理解，熟练掌握构造树的方法
int constructSTUtil(vector<int>& input, int start, int end, vector<int>& st, int current) {
    if (start == end) {
        st[current] = input[start];
        return input[start];
    }
    // 递归从底部开始构造数，真他妈的有意思
    int mid = getMid(start, end);
    st[current] = constructSTUtil(input, start, mid, st, current*2+1) +
        constructSTUtil(input, mid+1, end, st, current*2+2);
    return st[current];
}

// 构造segment tree，需要掌握递归调用的方法，以及树的高度/节点数量的计算方式
vector<int> constructST(vector<int>& input) {
    int n = input.size();
    int height = ceil(log2(input.size()));
    int nodesCount = 2 * (int)pow(2, height) - 1;
    vector<int> st(nodesCount, 0);
    constructSTUtil(input, 0, n-1, st, 0);
    return st;
}

// 用于递归求和的函数
int getSumUtil(vector<int>& st, int start, int end, int qstart, int qend, int current) {
    // 要查询的区间包含当前区间
    if (qstart <= start && qend >= end) {
        return st[current];
    }
    // 要查询的区间不在当前区间内
    if (end < qstart || start > qend) {
        return 0;
    }
    int mid = getMid(start, end);
    return getSumUtil(st, start, mid, qstart, qend, current*2+1) +
        getSumUtil(st, mid+1, end, qstart, qend, 2*current+2);
}

// 求某个区间的和，需要掌握求和方法
int getSum(vector<int>& st, int n, int start, int end) {
    if (start < 0 || end > n-1 || start > end) {
        return -1;
    }
    return getSumUtil(st, 0, n-1, start, end, 0);
}

void updateValueUtil(vector<int>& st, int start, int end, int index, int diff, int current) {
    // 要更新的索引不在当前索引范围内，不需要更新
    if (index < start || index > end) {
        return;
    }
    // 更新对应索引的值
    st[current] = st[current] + diff;
    // 需要更新父节点
    if (start != end) {
        int mid = getMid(start, end);
        updateValueUtil(st, start, mid, index, diff, 2*current+1);
        updateValueUtil(st, mid+1, end, index, diff, 2*current+2);
    }
}

// 更新输入数组以及segment tree中的值，需要注意是递归更新的
void updateValue(vector<int>& input, vector<int>& st, int index, int newVal) {
    if (index < 0 || index > input.size()-1) {
        return;
    }
    // 求得和原始值的差值
    int diff = newVal - input[index];
    // 更新数据
    input[index] = newVal;
    // 递归调用，更新merge节点
    updateValueUtil(st, 0, input.size()-1, index, diff, 0);
}

int main() {
    int a[] = {1,3,5,7,9,11};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> st = constructST(input);
    printVector(st);

    cout << getSum(st, input.size(), 1, 3) << endl;

    updateValue(input, st, 1, 10);
    cout << getSum(st, input.size(), 1, 3) << endl;
}
