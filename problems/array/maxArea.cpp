#include "../include.h"

/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at 
 * coordinate (i, ai). n vertical lines are drawn such that the two endpoints of 
 * line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
 * forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 */

// 稍微高效一点的解法
int maxArea2(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int max = 0;
    while (i < j) {
        int h = height[i] < height[j] ? height[i] : height[j];
        int area = (j - i) * h;
        if (area > max) {
            max = area;
        }
        while (height[i] <= h && i < j) {
            i++;
        }
        while (height[j] <= h && i < j) {
            j--;
        }
    }
    return max;
}

// 使用双指针，关键是根据题目要求找到数学规律，再思考解法
int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int max = 0;
    while (i < j) {
        int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
        if (area > max) {
            max = area;
        }
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max;
}

int main(int argc, char** argv) {
    int a[] = {4,3,2,7,8,2,3,1};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << maxArea2(input) << endl;
    return 0;
}
