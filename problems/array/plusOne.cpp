#include "../include.h"

/**
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    if (n == 0) {
        digits.push_back(1);
        return digits;
    }
    int d;
    int s = 0;
    for (int i=n-1; i>=0; i--) {
        d = digits[i] + s;
        if (i == n-1) {
            d += 1;
        }
        if (d >= 10) {
            s = d/10;
            d = d % 10;
            digits[i] = d;
        } else {
            digits[i] = d;
            return digits;
        }
    }
    if (s > 0) {
        digits.insert(digits.begin(), s);
    }
    return digits;
}

int main(int argc, char** argv) {
    int a[] = {3,3,9,9,9};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> output = plusOne(input);
    printVector(output);
}
