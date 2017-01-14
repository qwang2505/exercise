#include "../include.h"

/**
 * Given an array of integers and an integer k, find out whether there are two distinct 
 * indices i and j in the array such that nums[i] = nums[j] and the absolute difference 
 * between i and j is at most k.
 */

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> m;
    for (int i=0; i < nums.size(); i++) {
        map<int, int>::iterator it = m.find(nums[i]);
        if (it == m.end()) {
            m[nums[i]] = i;
        } else {
            int index = it->second;
            if (i - index <= k) {
                return true;
            } else {
                m[nums[i]] = i;
            }
        }
    }
    return false;
}


int main(int argc, char** argv) {
    int a[] = {1, 3, 2, 6, 5, 4, 1, 2};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    cout << containsNearbyDuplicate(input, 2) << endl;
    cout << containsNearbyDuplicate(input, 4) << endl;
    cout << containsNearbyDuplicate(input, 5) << endl;
    cout << containsNearbyDuplicate(input, 6) << endl;
}
