#include "../include.h"


/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 */


/**
 * TRICK: 当提到不要使用额外存储空间的时候，首先可以考虑在输入上做修改，或者在输出上尽可能多的存储信息
 *
 * NOTICE:
 * 1. 数组索引是0-based, 数组值是1-based
 * 2. 修改了输入数组
 */
vector<int> findDispearedNumbers(vector<int>& nums) {
    vector<int> output;
    for (int i=0; i < nums.size(); i++) {
        // index is 0 based, value is 1 based
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            output.push_back(i+1);
        }
    }
    return output;
}


int main(int argc, char** argv) {
    int a[] = {4,3,2,7,8,2,3,1};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<int> output = findDispearedNumbers(input);
    printVector(output);
    return 0;
}
