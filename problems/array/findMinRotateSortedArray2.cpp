#include "../include.h"

/**
 *
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size()-1, mid = 0;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) {
            lo = mid + 1;
        } else if (nums[mid] < nums[hi]) {
            hi = mid;
        } else {
            // nums[mid] == nums[high], 此时不能判断最小点落在哪边，所以将
            // high--，重新检测。这导致最快情况下时间复杂度为O(n)
            hi--;
        }
    }
    return nums[lo];
}

int main() {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));

    cout << findMin(input) << endl;
}
