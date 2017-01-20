#include "../include.h"

/**
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */


// TODO 使用分治算法，效率能更提升一点
int findByDC(vector<int>& nums) {
}

// O(n), 动态规划。空间使用率可以优化，只用O(1) space即可
int findByDP(vector<int>& nums) {
    if (nums.size() < 1) {
        return 0;
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int max = dp[0];
    for (int i=1; i < nums.size(); i++) {
        dp[i] = nums[i] > dp[i-1] + nums[i] ? nums[i] : dp[i-1] + nums[i];
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}


int maxSubArray(vector<int>& nums) {
    //return findByDP(nums);
    return findByDC(nums);
}

int main(int argc, char** argv) {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << maxSubArray(input) << endl;
    return 0;
}
