#include "../include.h"

/**
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */

// 使用map存储数组的每个元素后面有多少个连续的元素，在遍历中更新map中的值，并track最大值
// 整体思路还是比较容易想到的，但是细节部分的处理要注意，想清楚map的值表示的是什么
// 在这里map的值表示的是以当前元素为起始，有多少个连续递增数，包含当前元素，所以初始化为1
int longestConsecutive(vector<int>& nums) {
    map<int, int> m;
    // 初始化为1，至少有一个连续递增数
    for (int i=0; i < nums.size(); i++) {
        m[nums[i]] = 1;
    }

    int maxN = 0;
    // 在循环中更新map的值，通过在map中记录值避免重复更新
    for (int i=0; i < nums.size(); i++) {
        if (m[nums[i]] > 1) {
            continue;
        }
        int num = nums[i] + 1;
        int c = 1;
        while (m.find(num) != m.end()) {
            c += m[num];
            // 大于1表示已经更新过了，不要再重复更新
            if (m[num] > 1) {
                break;
            } else {
                // 否则，继续检测下一个元素是否存在
                num++;
            }
        }
        // 将获取到的结果更新，c表示以当前元素为起始、连续整数的数量
        m[nums[i]] = c;
        if (c > maxN) {
            maxN = c;
        }
    }
    return maxN;
}

int main() {
    int a[] = {100,4,200,1,3,2};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));

    cout << longestConsecutive(input) << endl;
}
