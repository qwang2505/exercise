#include "../include.h"

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 */

// time limit exceeded
// call with: jump(nums, 0);
bool jump(vector<int>& nums, int index) {
    if (index == nums.size()-1) {
        return true;
    }
    for (int i=1; i <= nums[index]; i++) {
        bool r = jump(nums, index+i);
        if (r) {
            return r;
        }
    }
    return false;
}

// 这里的重点是条件i<=reach，这个条件控制了达不到后面的情况。需要好好理解。
// 注意思路，这些问题实际上应该说是理解不难，但是思路都不能容易想到
bool canJump(vector<int>& nums) {
    int i = 0;
    for (int reach=0; i < nums.size() && i <= reach; i++) {
        reach = max(reach, i + nums[i]);
    }
    return i == nums.size();
}

int main(int argc, char** argv) {
    int a[] = {2,3,1,1,4};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << canJump(input) << endl;

    int a1[] = {3,2,1,0,4};
    vector<int> input1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    cout << canJump(input1) << endl;
    return 0;
}
