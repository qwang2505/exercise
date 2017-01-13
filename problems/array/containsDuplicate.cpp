#include "../include.h"

/**
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 */

bool containsDuplicate(vector<int>& nums){
    map<int, bool> m;
    for (int i=0; i < nums.size(); i++) {
        if (m[nums[i]]) {
            return true;
        } else {
            m[nums[i]] = true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int a[] = {4,3,2,7,8,2,3,1};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    cout << containsDuplicate(input) << endl;
    return 0;
}
