#include "../include.h"

/**
 * Given an integer array of size n, find all elements that appear more than 
 * ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 *
 * Hint:
 * 1. How many majority elements could it possibly have?
 */

// 使用了moore voting algorithm类似的思路，应该是经过证明的吧，
// 解法简单明了，类似问题也许都可以这么解
vector<int> majorityElement(vector<int>& nums) {
    int major1 = 0, major2 = 0;
    int cnt1 = 0, cnt2 = 0;
    int n = nums.size();
    for (int i=0; i < n; i++) {
        if (cnt1 > 0 && major1 == nums[i]) {
            cnt1++;
        } else if (cnt2 > 0 && major2 == nums[i]) {
            cnt2++;
        } else if (cnt1 == 0) {
            major1 = nums[i];
            cnt1 = 1;
        } else if (cnt2 == 0) {
            major2 = nums[i];
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = cnt2 = 0;
    for (int i=0; i < n; i++) {
        if (nums[i] == major1) {
            cnt1++;
        } else if (nums[i] == major2) {
            cnt2++;
        }
    }

    vector<int> output;
    if (cnt1 > n/3) {
        output.push_back(major1);
    }
    if (cnt2 > n/3) {
        output.push_back(major2);
    }
    return output;
}

int main(int argc, char** argv) {
    //int a[] = {1, 2, 3, 3, 2, 3, 1};
    //int a[] = {1, 2, 3, 3, 2, 3, 1, 2};
    int a[] = {0, 0, 0};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> output = majorityElement(input);
    printVector(output);
}
