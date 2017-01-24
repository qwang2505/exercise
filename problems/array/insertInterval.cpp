#include "../include.h"

/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

Interval mergeTwoInterval(Interval a, Interval b) {
    Interval ret(a.start, a.end >= b.end ? a.end : b.end);
    return ret;
}

// a.start must be less than or equal with b.start
bool overlap(Interval a, Interval b) {
    return a.end >= b.start;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> output;
    if (intervals.size() == 0) {
        output.push_back(newInterval);
        return output;
    }

    Interval *p = &newInterval;
    for (int i=0; i < intervals.size(); i++) {
        if (p != NULL) {
            Interval first = p->start < intervals[i].start ? *p : intervals[i];
            Interval second = p->start < intervals[i].start ? intervals[i] : *p;
            if (overlap(first, second)) {
                *p = mergeTwoInterval(first, second);
            } else if (p->start < intervals[i].start) {
                output.push_back(*p);
                output.push_back(intervals[i]);
                p = NULL;
            } else {
                output.push_back(intervals[i]);
            }
        } else {
            output.push_back(intervals[i]);
        }
    }
    if (p != NULL) {
        output.push_back(*p);
    }
    return output;
}

void print(vector<Interval>& intervals) {
    for (int i=0; i < intervals.size(); i++) {
        cout << "[" << intervals[i].start << "," << intervals[i].end << "],";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    vector<Interval> input;
    input.push_back(Interval(1,3));
    input.push_back(Interval(6, 9));
    vector<Interval> output = insert(input, Interval(2,5));
    print(output);

    input.clear();
    input.push_back(Interval(1,2));
    input.push_back(Interval(3,5));
    input.push_back(Interval(6,7));
    input.push_back(Interval(8,10));
    input.push_back(Interval(12,16));
    output = insert(input, Interval(4,9));
    print(output);
}
