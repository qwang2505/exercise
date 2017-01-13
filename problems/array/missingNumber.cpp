#include "../include.h"

/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

// 利用数学规律，只有在只缺失一个值的时候适用，不要求顺序
int findMissingWithSum(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return n * (n + 1) / 2 - sum;
}

// 有点不理解。好像并没有什么原理可以参考，先记住这种方法吧，后面肯定还要用到很多，慢慢再取熟悉
int findByBitManipulation(vector<int>& nums) {
    int result = nums.size();
    for (int i=0; i < nums.size(); i++) {
        result ^= nums[i];
        result ^= i;
    }
    return result;
}

// 根据二分查找来解决，时间复杂度是O(nlgn)
int findByBinarySearch(vector<int>& nums, int min, int max) {
    if (max < min) {
        return min;
    }
    int n = nums.size();
    int mid = (min + max) / 2;
    int lessCount = 0;
    int expLessCount = mid;
    bool found = false;
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] < mid) {
            lessCount++;
        } else if (nums[i] == mid) {
            found = true;
        }
    }
    if (!found) {
        return mid;
    } else if (lessCount < expLessCount) {
        return findByBinarySearch(nums, min, mid-1);
    } else {
        return findByBinarySearch(nums, mid+1, max);
    }
}


int missingNumber(vector<int>& nums) {
    //return findMissingWithSum(nums);
    //return findByBinarySearch(nums, 0, nums.size()-1);
    return findByBitManipulation(nums);
}


int main(int argc, char** argv) {
    int a[] = {3, 0, 1};
    //int a[] = {0};
    vector<int> input(a, a + sizeof(a) / sizeof(a[0]));
    cout << missingNumber(input) << endl;
}
