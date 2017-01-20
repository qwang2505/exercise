#include "../include.h"

/**
 * Given a set of candidate numbers (C) (without duplicates) and a target 
 * number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * [
 *   [7],
 *   [2, 2, 3]
 * ]
 */

void canSum(vector<int>& candidates, int target, vector<int>& cache, vector<vector<int> >& result, int begin) {
    for (int i=begin; i < candidates.size(); i++) {
        if (candidates[i] == target) {
            vector<int> r(cache);
            r.push_back(candidates[i]);
            sort(r.begin(), r.end());
            result.push_back(r);
        } else if (candidates[i] < target) {
            cache.push_back(candidates[i]);
            canSum(candidates, target-candidates[i], cache, result, i);
            cache.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > result;
    vector<int> cache;
    canSum(candidates, target, cache, result, 0);
    return result;
}

int main(int argc, char** argv) {
    //int a[] = {2,3,6,7};
    int a[] = {2,3,5};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<vector<int> > output = combinationSum(input, 7);
    printVector(output);
    return 0;
}
