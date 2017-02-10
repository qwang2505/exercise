#include "../include.h"

/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */


// 想的太简单了，没有充分考虑所有情况
int maxProductBad(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int prod = 1;
    int maxP = numeric_limits<int>::min();
    for (int i=0; i < nums.size(); i++) {
        int p = prod * nums[i] > nums[i] ? prod * nums[i] : nums[i];
        if (p > maxP) {
            maxP = p;
        }
        prod = p;
    }
    return maxP;
}

// 这次应该是正确的解答了吧
// 不对，放弃了
int maxProductStillBad(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    int lastP = 0, lastN = 0;
    int maxP = numeric_limits<int>::min();
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            lastP = max(lastP, nums[i] * lastN);
            lastN = min(lastN, max(nums[i] * lastP, nums[i]));
        } else {
            lastP = max(lastP, max(nums[i], nums[i] * lastP));
            lastN = min(lastN, nums[i] * lastN);
        }
        if (lastP != 0 && lastP > maxP) {
            maxP = lastP;
        }
    }
    return maxP;

}

// 这才是正确的解法，实际上也挺简单的，但是为什么就是想不到？？？
int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int maxpre = nums[0];
    int minpre = nums[0];
    int maxP = nums[0];
    int maxhere, minhere;

    for (int i=1; i < nums.size(); i++) {
        maxhere = max(max(maxpre * nums[i], minpre * nums[i]), nums[i]);
        minhere = min(min(maxpre * nums[i], minpre * nums[i]), nums[i]);
        maxP = max(maxP, maxhere);
        maxpre = maxhere;
        minpre = minhere;
    }
    return maxP;
}

int main() {
    int a[] = {2,3,-2,4};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));

    cout << maxProduct(input) << endl;
}
