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


vector<vector<int>> fourSum(vector<int>& nums, int target) {

}

int main(int argc, char** argv) {
    int a[] = {1,0,-1,0,-2,2};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<vector<int> > output = fourSum(input);
    printVector(output);

    return 0;
}
