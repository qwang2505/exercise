#include "../include.h"

/**
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 */

/**
 * 本来限制O(1)空间的时候，应该考虑在输入或者输出上做修改。但是现在不允许在输入在修改。需要想别的办法。
 *
 * 第一步：证明，使用Pigeonholl principle
 */

// 基于二分查找实现
// 挺巧妙的思路，看来二分查找是真神器啊，好好理解，尝试多使用
int binarySearch(const vector<int>& nums, int min, int max) {
    int mid = (min + max) / 2;
    int n = nums.size() - 1;
    int expLessCount = mid - 1;
    int lessCount = 0;
    int equalCount = 0;
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] < mid) {
            lessCount++;
        } else if (nums[i] == mid) {
            equalCount++;
            if (equalCount > 1) {
                return mid;
            }
        }
    }
    if (lessCount > expLessCount) {
        return binarySearch(nums, min, mid-1);
    } else {
        return binarySearch(nums, mid+1, max);
    }
    return -1;
}

// 双指针方法，这个是比较trick的方法，参考链表循环检测的方法.
// TODO 暂时还不太理解为什么可以这么简单找到重复的元素，需要详细看看
int twoPointers(const vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }
    fast = nums[0];
    while (true) {
        if (fast == slow) {
            return fast;
        }
        fast = nums[fast];
        slow = nums[slow];
    }
    return -1;
}

int findDuplicate(const vector<int>& nums) {
    //return binarySearch(nums, 0, nums.size()-1);
    return twoPointers(nums);
}

int main(int argc, char** argv) {
    int a[] = {1,2,3,4,5,6,7,8,9,4,10,11,12};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << findDuplicate(input) << endl;
}
