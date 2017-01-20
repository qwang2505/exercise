#include "../include.h"

/**
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */

int firstMissingPositive(vector<int>& nums) {
    for (int i=0; i < nums.size(); i++) {
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
            int temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
        }
    }
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main(int argc, char** argv) {
    int a[] = {1,2,0};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << firstMissingPositive(input) << endl;

    int a1[] = {3,4,-1,1};
    vector<int> input1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    cout << firstMissingPositive(input1) << endl;
    return 0;
}
