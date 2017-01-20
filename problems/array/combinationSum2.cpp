#include "../include.h"

/**
 *
 * Given a collection of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 */

void canSum(vector<int>& candidates, int target, vector<int>& cache, vector<vector<int> >& result, int begin) {
    for (int i=begin; i < candidates.size(); i++) {
        if (candidates[i] == target) {
            vector<int> r(cache);
            r.push_back(candidates[i]);
            sort(r.begin(), r.end());
            result.push_back(r);
            break;
        } else if (candidates[i] < target) {
            cache.push_back(candidates[i]);
            canSum(candidates, target-candidates[i], cache, result, i+1);
            cache.pop_back();
        } else {
            break;
        }
        while (i < candidates.size()-1 && candidates[i] == candidates[i+1]) {
            i++;
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > result;
    vector<int> cache;
    canSum(candidates, target, cache, result, 0);
    return result;
}

int main(int argc, char** argv) {
    int a[] = {10,1,2,7,6,1,5};
    vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
    vector<vector<int> > output = combinationSum2(input, 8);
    printVector(output);
    return 0;
}
