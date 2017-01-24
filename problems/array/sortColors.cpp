#include "../include.h"

/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of 
 * the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * 1. A rather straight forward solution is a two-pass algorithm using counting sort.
 * 1. First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 */

void sortColors(vector<int>& nums) {
    vector<int> s(3, 0);
    for (int i=0; i < nums.size(); i++) {
        s[nums[i]] += 1;
    }
    int index = 0;
    for (int i=0; i < s.size(); i++) {
        for (int j=0; j < s[i]; j++) {
            nums[index++] = i;
        }
    }
}

int main(int argc, char** argv) {
    int a[] = {2,1,0,0,2,1,1,1,0,0,1,2,2};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    sortColors(input);
    printVector(input);
}
