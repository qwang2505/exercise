#include "../include.h"

/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

/**
 * Reverse values of array from 'from' to 'to' indexes.
 */
void reverse(vector<int>& nums, int from, int to) {
    int start = from, end = to;
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

/**
 * 经典算法，目前还没找到别的算法，步骤如下：
 * 1. Find largest k, such that nums[k] < nums[k+1]. If no such k exists, just reverse the whole array and we are done
 * 2. Find largest l, such that nums[k] < nums[l] and k < l.
 * 3. Swap values at k and l.
 * 4. Reverse array from k+1 to n-1
 */
void nextPermutation(vector<int>& nums) {
    int k = -1, l = -1;
    int n = nums.size();
    // first step, find k
    for (int i=n-2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            k = i;
            break;
        }
    }
    // if k not exists, just reverse whole array
    if (k == -1) {
        reverse(nums, 0, n-1);
        return;
    }
    // second step, find l
    for (int i=n-1; i > k; i--) {
        if (nums[k] < nums[i]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        return;
    }
    // third step, swap values at k and l
    int temp = nums[k];
    nums[k] = nums[l];
    nums[l] = temp;
    // fourth step, reverse values from k+1 to n-1
    reverse(nums, k+1, n-1);
}

int main(int argc, char** argv) {
    int a[] = {1,2,3};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    nextPermutation(input);
    printVector(input);

    return 0;
}
