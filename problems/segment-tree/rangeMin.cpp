#include "../include.h"

/**
 * We have an array arr[0 . . . n-1]. We should be able to efficiently find the minimum value from 
 * index qs (query start) to qe (query end) where 0 <= qs <= qe <= n-1.
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
    int left = constructSTUtil(input, start, mid, st, current*2+1);
    int right = constructSTUtil(input, mid+1, end, st, current*2+2);
    st[current] = left < right ? left : right;
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

// 递归查找某个区间的最小值，注意递归的方法，很有意思的算法
int rangeMinUtil(vector<int>& st, int start, int end, int qstart, int qend, int current) {
    // 要查询的区间包含当前区间
    if (qstart <= start && qend >= end) {
        return st[current];
    }
    // 要查询的区间不在当前区间内
    if (end < qstart || start > qend) {
        return numeric_limits<int>::max();
    }
    int mid = getMid(start, end);
    int left = rangeMinUtil(st, start, mid, qstart, qend, 2*current+1);
    int right = rangeMinUtil(st, mid+1, end, qstart, qend, 2*current+2);
    return left < right ? left : right;
}

// 查找某个区间中的最小值，注意递归的查找方法
int rangeMin(vector<int>& st, int n, int start, int end) {
    if (start < 0 || end > n-1 || start > end) {
        return -1;
    }
    return rangeMinUtil(st, 0, n-1, start, end, 0);
}

int main() {
    int a[] = {1,3,2,7,9,11};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> st = constructST(input);
    printVector(st);

    cout << rangeMin(st, input.size(), 1, 5) << endl;
}
