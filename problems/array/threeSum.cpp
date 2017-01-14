#include "../include.h"

/**
 * Given an array S of n integers, are there elements a, b, c in S such that 
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

// 笨解法，时间复杂度O(n3)
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > output;
    for (int i=0; i < nums.size(); i++) {
        for (int j=i+1; j < nums.size(); j++) {
            for (int x=j+1; x < nums.size(); x++) {
                if (nums[i] + nums[j] + nums[x] == 0) {
                    vector<int> *a = new vector<int>();
                    a->push_back(nums[i]);
                    a->push_back(nums[j]);
                    a->push_back(nums[x]);
                    sort(a->begin(), a->end());
                    output.push_back(*a);
                }
            }
        }
    }
    sort(output.begin(), output.end());
    output.erase(unique(output.begin(), output.end()), output.end());
    return output;
}

// 先排序，再使用双指针来找到满足条件的元素，同时还能避免重复问题
// 时间复杂度O(n2)
//
// TRICK: 要注意什么时候向前后移动，在避免重复的同时，考虑各种情况
vector<vector<int> > threeSum1(vector<int>& nums) {
    // 先排序
    sort(nums.begin(), nums.end());

    vector<vector<int> > output;
    if (nums.size() < 3) {
        return output;
    }

    int last_val = 0;
    for (int i=0; i < nums.size()-2; i++) {
        // 要找的target
        int target = -nums[i];
        // 重复元素不要重复找
        if (i > 0 && last_val == nums[i]) {
            continue;
        }

        // 接下来使用双指针的方法来找两个数的和为target。因为是有序的，就比较容易了
        int first = i+1, last = nums.size()-1;
        while (first < last) {

            int sum = nums[first] + nums[last];
            if (sum == target) {
                vector<int> a;
                a.push_back(nums[i]);
                a.push_back(nums[first]);
                a.push_back(nums[last]);
                output.push_back(a);
                while (first < last && nums[first] == a[1]) {
                    first++;
                }
                while (first < last && nums[last] == a[2]) {
                    last--;
                }
            } else if (sum < target) {
                first++;
            } else if (sum > target) {
                last--;
            }
        }

        last_val = nums[i];
    }
    return output;
}


int main(int argc, char** argv) {
    //int a[] = {-1,0,1,2,-1,-4};
    int a[] = {-1,-1,1,1,0,0,1,1,-1,-1,0,0};
    //int a[] = {-2,0,0,2,2};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<vector<int> > output = threeSum1(input);
    printVector(output);

    return 0;
}
