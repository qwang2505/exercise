#include "../include.h"

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * UPDATE (2016/2/13):
 * The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> output;
    for (int i=0; i < nums.size(); i++) {
        map<int, int>::iterator it = m.find(target - nums[i]);
        if (it == m.end()) {
            m[nums[i]] = i;
        } else {
            output.push_back(m[target-nums[i]]);
            output.push_back(i);
            return output;
        }
    }
    return output;
}

int main(int argc, char** argv) {
    int a[] = {2, 7, 11, 15};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> output = twoSum(input, 9);
    printVector(output);
}
