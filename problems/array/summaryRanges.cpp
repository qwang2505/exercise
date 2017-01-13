#include "../include.h"

/**
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

string getRange(int start, int end) {
    ostringstream s;
    if (start != end) {
        s << start << "->" << end;
    } else {
        s << start;
    }
    return s.str();
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> output;
    if (nums.size() == 0) {
        return output;
    }
    int lastStart, lastEnd;
    lastStart = lastEnd = nums[0];
    for (int i=1; i < nums.size(); i++) {
        if (lastEnd + 1 != nums[i]) {
            output.push_back(getRange(lastStart, lastEnd));
            lastStart = lastEnd = nums[i];
        } else {
            lastEnd = nums[i];
        }
    }
    output.push_back(getRange(lastStart, lastEnd));

    return output;
}

int main(int argc, char** argv) {
    int a[] = {0, 1, 2, 4, 5, 7};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<string> output = summaryRanges(input);
    printVector(output);
}
