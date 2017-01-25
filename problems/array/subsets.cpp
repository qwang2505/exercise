#include "../include.h"

/**
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

int moveIndex(vector<int>& indexes, int cur, int n, int k) {
    if (indexes[cur] < n-k+cur) {
        indexes[cur]++;
        return cur;
    } else if (cur == 0) {
        return -1;
    } else {
        while (cur >= 0 && indexes[cur] >= n-k+cur) {
            cur--;
        }
        if (cur < 0) {
            return cur;
        }
        indexes[cur]++;
        for (int i=cur+1; i < k; i++) {
            indexes[i] = indexes[i-1] + 1;
        }
        return k-1;
    }
}

vector<int> getSubset(vector<int>& nums, vector<int>& indexes) {
    vector<int> output(indexes.size());
    for (int i=0; i < indexes.size(); i++) {
        output[i] = nums[indexes[i]];
    }
    return output;
}

// get subsets from nums which contains k elements
void kSubsets(vector<int>& nums, int k, vector<vector<int> >& result) {
    if (k == 0) {
        result.push_back(vector<int>());
        return;
    } else if (k == nums.size()) {
        result.push_back(nums);
        return;
    }
    vector<int> indexes(k);
    // 初始化索引
    for (int i=0; i < k; i++) {
        indexes[i] = i;
    }
    int n = nums.size();
    int cur = k-1;
    while (cur >= 0) {
        // 添加到输出中
        result.push_back(getSubset(nums, indexes));
        // 增加索引值
        cur = moveIndex(indexes, cur, n, k);
    }
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > output;
    for (int i=0; i < nums.size()+1; i++) {
        kSubsets(nums, i, output);
    }
    return output;
}

int main(int argc, char** argv) {
    //int a[] = {1,2,3};
    int a[] = {3,2,4,1};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<vector<int> > output = subsets(input);
    printVector(output);
}
