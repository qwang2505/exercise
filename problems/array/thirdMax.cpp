#include "../include.h"

/**
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 *
 * Example 1:
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 *
 * Example 2:
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 *
 * Example 3:
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 */

/**
 * 一个看起来很简单的题目，实际上解决起来并不是特别容易，细节容易出问题。如果是用
 * JAVA或者PYTHON之类的语言，max有没有赋值容易判断，但是对于C++就需要用额外的变量
 * 来判断。做题的时候需要注意这些地方。好好阅读题目，充分理解，考虑每一种可能的情况。
 */
int thirdMax(vector<int>& nums) {
    int max1, max2, max3;
    max1 = max2 = max3 = numeric_limits<int>::min();
    int count = 0;
    for (int i=0; i < nums.size(); i++) {
        // 这里是比较难理解的，也是解决最小值问题的关键
        if (nums[i] == max1 || nums[i] == max2) {
            continue;
        }
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
            count++;
        } else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
            count++;
        } else if (nums[i] >= max3) {
            max3 = nums[i];
            count++;
        }
    }
    return count >= 3 ? max3 : max1;
}

int main(int argc, char** argv) {
    int a1[] = {3, 2, 1, 4, 6, 5, 5};
    vector<int> input1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    int output1 = thirdMax(input1);
    cout << "input: " << endl;
    printVector(input1);
    cout << "third max: " << output1 << endl << endl;

    int a2[] = {1, 2};
    vector<int> input2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    int output2 = thirdMax(input2);
    cout << "input: " << endl;
    printVector(input2);
    cout << "third max: " << output2 << endl << endl;

    int a3[] = {1, 2};
    vector<int> input3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    input3.push_back(numeric_limits<int>::min());
    int output3 = thirdMax(input3);
    cout << "input: " << endl;
    printVector(input3);
    cout << "third max: " << output3 << endl << endl;

    return 0;
}
