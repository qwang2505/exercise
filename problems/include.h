#ifndef _INCLUDE_H
#define _INCLUDE_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <algorithm>
#include <string>
#include <sstream>

#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

template <typename T>
inline void printVector(vector<T>& input) {
    cout << "[";
    for (int i=0; i < input.size(); i++) {
        cout << input[i];
        if (i != input.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template <typename T>
inline void printVector(vector<vector<T> >& input) {
    cout << "[" << endl;
    for (int j=0; j < input.size(); j++) {
        cout << "\t[";
        for (int i=0; i < input[j].size(); i++) {
            cout << input[j][i];
            if (i != input[j].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
}

inline int random(int start, int end) {
    srand(time(NULL));
    if (end < start) {
        return 0;
    }
    int size = end - start + 1;
    int r = rand() % size;
    return start + r;
}

#endif
