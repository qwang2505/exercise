#include "../include.h"

/**
 * Given n non-negative integers representing an elevation 
 * map where the width of each bar is 1, compute how much 
 * water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

int trap(vector<int>& height) {
    return 0;
}

int main(int argc, char** argv) {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << trap(input) << endl;
    return 0;
}
