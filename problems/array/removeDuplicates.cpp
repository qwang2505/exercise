#include "../include.h"

/**
 * Given a sorted array, remove the duplicates in place such that each 
 * element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in 
 * place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements 
 * of nums being 1 and 2 respectively. It doesn't matter what you leave 
 * beyond the new length.
 */

int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) {
        if (nums[slow] == nums[fast]) {
            fast++;
        } else {
            nums[++slow] = nums[fast++];
        }
    }
    return slow+1;
}

int main(int argc, char** argv) {
    int a[] = {1,1,2};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << removeDuplicates(input) << endl;
    return 0;
}
