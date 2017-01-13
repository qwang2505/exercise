#include "../include.h"

/**
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 */

/**
 * TRICK: O(1)空间，考虑在输入上做修改，或者在输出上记录更多信息
 */
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> output;
    for (int i=0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        } else {
            output.push_back(abs(nums[i]));
        }
    }
    return output;
}

int main(int argc, char** argv) {
    int a[] = {4,3,2,7,8,2,3,1};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<int> output = findDuplicates(input);
    printVector(output);
    return 0;
}
