#include "../include.h"

/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2, with the first two elements of nums being 2.
 *
 * Hint:
 * 1. Try two pointers.
 * 2. Did you use the property of "the order of elements can be changed"?
 * 3. What happens when the elements to remove are rare?
 */


int naiveSolution(vector<int>& nums, int val) {
    int n = nums.size();
    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] == val) {
            fast++;
        } else {
            nums[slow++] = nums[fast++];
        }
    }
    return slow;
}


int removeElement(vector<int>& nums, int val) {
    return naiveSolution(nums, val);
}


int main(int argc, char** argv) {
    int a[] = {3,2,2,3};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << removeElement(input, 3) << endl;
    return 0;
}
