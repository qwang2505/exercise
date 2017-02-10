#include "../include.h"

/**
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * click to show spoilers.
 *
 * Note:
 * Your solution should be in logarithmic complexity.
 */

// 二分查找
int findPeakElement2(vector<int>& nums) {
    int l = 0, h = nums.size()-1, mid, mid2;
    while (l < h) {
        mid = l + (h - l) / 2;
        mid2 = mid + 1;
        if (nums[mid] > nums[mid2]) {
            h = mid;
        } else {
            l = mid2;
        }
    }
    return l;
}

// sequential search
// 复杂度是O(n)
int findPeakElement(const vector<int> &num) {
    for(int i = 1; i < num.size(); i ++)
    {
        if(num[i] < num[i-1])
        {
            return i-1;
        }
    }
    return num.size()-1;
}

int main() {
    int a[] = {1,2,3,1};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    cout << findPeakElement(input) << endl;
}
