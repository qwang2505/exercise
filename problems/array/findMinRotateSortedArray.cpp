#include "../include.h"

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

int search(vector<int>& nums, int start, int end) {
    if (start == end) {
        return nums[start];
    }
    int mid = (start + end) / 2;
    if (nums[mid] > nums[end]) {
        return search(nums, mid+1, end);
    } else {
        return search(nums, start, mid);
    }
}

int findMin(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return min(nums[0], nums[1]);
    }
    if (nums[0] < nums[nums.size()-1]) {
        return nums[0];
    }
    return search(nums, 0, nums.size()-1);
}

int main() {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));

    cout << findMin(input) << endl;
}
