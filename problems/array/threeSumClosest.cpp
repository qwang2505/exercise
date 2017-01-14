#include "../include.h"


/**
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a 
 * given number, target. Return the sum of the three integers. You may assume that each input 
 * would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

// 参考threeSum的解法
int threeSumClosest(vector<int>& nums, int target) {
    // 先排序
    sort(nums.begin(), nums.end());

    int minDiff = numeric_limits<int>::max();
    int closest;
    for (int i=0; i < nums.size(); i++) {
        int t = target - nums[i];

        int front = i+1, back = nums.size()-1;
        while (front < back) {
            int sum = nums[front] + nums[back];
            int diff = abs(nums[i] + nums[front] + nums[back] - target);
            if (diff < minDiff) {
                closest = nums[i] + nums[front] + nums[back];
                minDiff = diff;
            }
            if (sum == t) {
                return target;
            } else if (sum < t) {
                front++;
            } else {
                back--;
            }
        }
    
        // 避免第一个元素重复
        if (i < nums.size() - 1 && nums[i] == nums[i+1]) {
            i++;
        }
    }
    return closest;
}

int main(int argc, char** argv) {
    int a[] = {-1,2,1,-4};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << threeSumClosest(input, 1) << endl;
    return 0;
}
