#include "../include.h"

/**
 * 反向输出栈，两个版本，使用两个栈来实现，以及不是用额外空间、利用递归来实现
 */


void reverseStack(vector<int>& input) {
    int value = input.back();
    input.pop_back();
    if (input.size() > 0) {
        reverseStack(input);
    }
    cout << value << "->";
}


/*
void reverseQueue(vector<int>& input) {
    int value = input.front();
    input.pop_front();
    if (input.size() > 0) {
        reverseQueue(input);
    }
    cout << value << "->";
}
*/


int main() {
    int a[] = {1,2,3,4,5,6,7,8};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    reverseStack(input);
    cout << endl;
}
