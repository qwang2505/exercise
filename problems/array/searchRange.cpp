#include "../include.h"

/**
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

// find the lowest index of target. if not found, return -1
int lowerBound(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, h = n-1;
    int mid = -1;
    while (l < h) {
        mid = (l + h) / 2;
        if (target <= nums[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    if (nums[l] != target) {
        return -1;
    }
    return l;
}

// find the largest index of target. if not found, return -1
int upperBound(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, h = n-1;
    int mid = -1;
    while (l < h) {
        mid = (l + h) / 2 + 1;
        if (target >= nums[mid]) {
            l = mid;
        } else {
            h = mid - 1;
        }
    }
    if (nums[l] != target) {
        return -1;
    }
    return h;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> output(2, -1);
    if (nums.size() == 0) {
        return output;
    }
    output[0] = lowerBound(nums, target);
    output[1] = upperBound(nums, target);
    return output;
}

int main(int argc, char** argv) {
    int a[] = {5,7,7,8,8,10};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<int> output = searchRange(input, 8);
    printVector(output);
    return 0;
}
