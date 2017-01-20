#include "../include.h"

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 */

int binarySearch(vector<int>& nums, int target, int l, int h) {
    if (l > h) {
        // not found
        return -1;
    }
    int mid = (l + h) / 2;
    if (target == nums[mid]) {
        return mid;
    }
    if (nums[l] <= nums[mid]) {
        if (nums[mid] > target && nums[l] <= target) {
            return binarySearch(nums, target, l, mid-1);
        } else {
            return binarySearch(nums, target, mid+1, h);
        }
    } else {
        if (nums[mid] < target && target <= nums[h]) {
            return binarySearch(nums, target, mid+1, h);
        } else {
            return binarySearch(nums, target, l, mid-1);
        }
    }
}

int search(vector<int>& nums, int target) { 
    return binarySearch(nums, target, 0, nums.size()-1);
}

int main(int argc, char** argv) {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << search(input, 3) << endl;
    cout << search(input, 5) << endl;
    cout << search(input, 2) << endl;
    return 0;
}
