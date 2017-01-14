#include "../include.h"

/**
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

// TODO 有时间需要再看这个题目的其他解法，时间复杂度可以优化到O(log(min(m, n)))


// 比较容易想到的解法，理解起来很容易，就是合并两个数组，找到中间位置的
// 元素，再求中位数。注意实现起来还是需要注意一些细节部分的，比如下面实现
// 中count的作用，如何保存中间位置的值，等等。这种解法的时间复杂度是O(n),
// 空间复杂度是O(1)
double findByTwoPointers(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m == 0 && n == 0) {
        return 0.0;
    }
    int l = m + n;
    int count = 0;
    double first, second;
    int i=0, j=0;
    int num;
    while (count <= l/2+1) {
        if (count == l/2+1) {
            first = num;
            break;
        }
        if (l % 2 == 0 && count == l/2) {
            second = num;
        }
        if (i >= m) {
            num = nums2[j];
            j++;
            count++;
        } else if (j >= n) {
            num = nums1[i];
            i++;
            count++;
        } else if (nums1[i] < nums2[j]) {
            num = nums1[i];
            i++;
            count++;
        } else {
            num = nums2[j];
            j++;
            count++;
        }
    }
    return l % 2 == 0 ? (first + second) / 2 : first;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return findByTwoPointers(nums1, nums2);
}

int main(int argc, char** argv) {
    int a1[] = {1,3};
    int a2[] = {2};
    vector<int> input1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> input2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    cout << findMedianSortedArrays(input1, input2) << endl;;

    int a3[] = {1,2};
    int a4[] = {3,4};
    vector<int> input3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    vector<int> input4(a4, a4 + sizeof(a4)/sizeof(a4[0]));
    cout << findMedianSortedArrays(input3, input4) << endl;;

    return 0;
}
