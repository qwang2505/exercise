#include "../include.h"

/**
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five 
 * elements of nums being 1, 1, 2, 2 and 3. It doesn't matter 
 * what you leave beyond the new length.
 */

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j=0; j < nums.size(); j++) {
        int n = nums[j];
        if (i < 2 || n > nums[i-2]) {
            nums[i++] = n;
        }
    }
    return i;
}

int main(int argc, char** argv) {
    //int a[] = {1,1,1,2,2,3};
    int a[] = {1,1,1,1,5,2,2,2,2,3,3};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    cout << removeDuplicates(input) << endl;
    printVector(input);
}
