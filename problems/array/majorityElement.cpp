#include "../include.h"

/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */


// 最直观的解法，时间复杂度O(n)，空间复杂度O(n)
int findByHashTable(vector<int>& nums) {
    map<int, int> m;
    int n = nums.size();
    for (int i=0; i < n; i++) {
        m[nums[i]]++;
        if (m[nums[i]] > n/2) {
            return nums[i];
        }
    }
    return -1;
}


// 先排序，再找中间位置
int findBySort(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
}


// 随机化算法，找到解是肯定的，时间复杂度如何也许需要证明
int findByRandom(vector<int>& nums) {
    int n = nums.size();
    while (true) {
        srand(time(NULL));
        int r = rand() % n;
        int c = nums[r];
        int count = 0;
        for (int i=0; i < n; i++) {
            if (nums[i] == c) {
                count++;
            }
        }
        if (count > n/2) {
            return c;
        }
    }
    return -1;
}

// 思路倒是可以理解，但是这种解法的时间复杂度如何呢？貌似是O(nlgn)?
int findByDivideAndConquer(vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    int mid = (left + right) / 2;
    int lm = findByDivideAndConquer(nums, left, mid);
    int rm = findByDivideAndConquer(nums, mid+1, right);
    if (lm == rm) {
        return lm;
    }
    return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
}

int findByMooreVotingAlgorithm(vector<int>& nums) {
    return 0;
}


int majorityElement(vector<int>& nums) {
    //return findByHashTable(nums);
    //return findBySort(nums);
    //return findByRandom(nums);
    //return findByDivideAndConquer(nums, 0, nums.size()-1);
    return findByMooreVotingAlgorithm(nums);
}

int main(int argc, char** argv) {
    int a[] = {1, 2, 3, 3, 2, 3, 3};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << majorityElement(input) << endl;
}
