#include "../include.h"

/**
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

// TODO 需要好好理解，写的时候不要出现bug
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, h = n-1;
    int mid;
    while (l <= h) {
        mid = (l + h) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return l;
}

int main(int argc, char** argv) {
    int a[] = {1,3,5,6};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << searchInsert(input, 5) << endl;
    cout << searchInsert(input, 2) << endl;
    cout << searchInsert(input, 7) << endl;
    cout << searchInsert(input, 0) << endl;
    return 0;
}
