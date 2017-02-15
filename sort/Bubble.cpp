#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../basic/util.h"

using namespace std;

void swap(vector<int>& array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * 进行冒泡排序
 */
void sort(vector<int> &array) {
    int n = array.size();
    for (int i=0; i < n; i++) {
        // 表示交换的次数
        int count = 0;
        for (int j=n-1; j > i; j--) {
            if (array[j] < array[j-1]) {
                swap(array, j-1, j);
                count++;
            }
        }
        // 如果交换的次数为0，表示在上一次循环中没有需要交换的元素，即数组已经
        // 有序，可以退出了
        if (count <= 0) {
            break;
        }
    }
}

int main(int argc, char** argv)
{
    // 注意数组的初始化方法
    //int a[] = {5,9,10,12,54,2,3,15};
    int a[] = {1,2,3,4,5,6,7,8,9};
    // 注意vector的初始化方法
    vector<int> array(a, a + sizeof(a)/sizeof(a[0]));
    // 传递引用，以便在内部修改
    sort(array);
    print(array);

    /*
    vector<int> input;
    randomVector(input, 20000000);
    long start = getTime();
    cout << "start sort" << endl;
    sort(input, 0, input.size() - 1);
    cout << "spend: " << getTime() - start << "ms." << endl;
    */
}
