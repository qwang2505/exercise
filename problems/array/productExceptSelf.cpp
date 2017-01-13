#include "../include.h"

/**
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> output(size, 1);
    for (int i=1; i < size; i++) {
        output[i] = output[i-1] * nums[i-1];
    }
    long r = nums[size-1];
    for (int i=size-2; i >= 0; i--) {
        output[i] = output[i] * r;
        r *= nums[i];
    }
    return output;
}

int main(int argc, char** argv) {
    int a[] = {1, 2, 3, 4};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<int> output = productExceptSelf(input);
    printVector(output);
}
