#include "../include.h"

/**
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval& a, Interval& b) {
    return a.start < b.start;
}

Interval mergeTwoInterval(Interval a, Interval b) {
    Interval ret(a.start, a.end >= b.end ? a.end : b.end);
    return ret;
}

bool overlap(Interval a, Interval b) {
    return a.end >= b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }
    // sort first
    sort(intervals.begin(), intervals.end(), compare);

    vector<Interval> resp;
    // test and merge
    Interval temp(intervals[0].start, intervals[0].end);
    for (int i=1; i < intervals.size(); i++) {
        if (overlap(temp, intervals[i])) {
            temp = mergeTwoInterval(temp, intervals[i]);
        } else {
            resp.push_back(Interval(temp.start, temp.end));
            temp.start = intervals[i].start;
            temp.end = intervals[i].end;
        }
    }
    resp.push_back(Interval(temp.start, temp.end));
    return resp;
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
    input.push_back(Interval(2,6));
    input.push_back(Interval(8,10));
    input.push_back(Interval(15,18));
    vector<Interval> output = merge(input);
    print(output);
}
