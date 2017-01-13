#include "../include.h"

/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

void moveZeros(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] == 0) {
            fast++;
        } else {
            nums[slow++] = nums[fast++];
        }
    }
    while (slow < nums.size()) {
        nums[slow++] = 0;
    }
}

int main(int argc, char** argv) {
    int a[] = {0,1,0,3,12};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    moveZeros(input);
    printVector(input);
}
