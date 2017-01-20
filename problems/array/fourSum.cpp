#include "../include.h"

/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such that 
 * a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */


vector<vector<int> > fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int> > output;
    if (n < 4) {
        return output;
    }
    for (int i=0; i < n-3; i++) {
        for (int j=i+1; j < n-2; j++) {
            int low = j+1, high = n-1;
            int t = target - nums[i] - nums[j];
            while (low < high) {
                if (nums[low] + nums[high] == t) {
                    vector<int> r(4);
                    r[0] = nums[i];
                    r[1] = nums[j];
                    r[2] = nums[low];
                    r[3] = nums[high];
                    output.push_back(r);
                    // move, skip duplicate
                    while (nums[low] == r[2] && low < high) {
                        low++;
                    }
                    while (low < high && nums[high] == r[3]) {
                        high--;
                    }
                } else if (nums[low] + nums[high] > t) {
                    high--;
                } else {
                    low++;
                }
            }
            while (j < n-3 && nums[j] == nums[j+1]) {
                j++;
            }
        }
        while (i < n-4 && nums[i] == nums[i+1]) {
            i++;
        }
    }
    return output;
}

int main(int argc, char** argv) {
    int a[] = {1,0,-1,0,-2,2};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<vector<int> > output = fourSum(input, 0);
    printVector(output);

    return 0;
}
