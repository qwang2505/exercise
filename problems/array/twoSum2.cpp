#include "../include.h"

/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

// two pointers, O(n)
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> output(2, 0);
    if (numbers.size() < 2) {
        return output;
    }
    int l = 0, h = numbers.size()-1;
    while (l < h) {
        int t = numbers[l] + numbers[h];
        if (t == target) {
            output[0] = l+1;
            output[1] = h+1;
            return output;
        } else if (t > target) {
            h--;
        } else {
            l++;
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
