#include "../include.h"

/**
 * Swap two numbers without temporary variable.
 */

void swapBySum(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}


void swapByXor(int& a, int& b) {
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int main(int argc, char** argv) {
    int a = 20;
    int b = 800;
    cout << "a: " << a << ", b: " << b << endl;

    swapBySum(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    swapByXor(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    return 0;
}
