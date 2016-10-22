/**
 * Count Sort
 *
 * Time = O(k + n), while k is the range of values of input array
 * Space = O(k + n), while k is the range of values of input array
 *
 * So if k = O(n), can use count sort to sort. If k >= Cnlgn, time
 * of count sort will be: O(nlgn), just like other sorting algorithms
 * like quick sort or merge sort, or even worse.
 */

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    for (int i=0; i < v.size(); i++)
    {
        cout << v[i] << "->";
    }
    cout << endl;
}

void sort(vector<int> &array) 
{
    int size = array.size();
    vector<int> output(size);
    int k = 0;
    // get highest number in input. Maybe also should get
    // minumum, but here don't do that
    for (int i=0; i < size; i++)
    {
        if (array[i] > k) 
        {
            k = array[i];
        }
    }
    // k + 1 because indexes start from 0, and k should
    // be the size of auxiliry vector
    k += 1;
    vector<int> aux(k, 0);

    // init auxiliry array so that aux[i] = |{k=i}| when k
    // is the value in input array
    for (int i=0; i < size; i++)
    {
        aux[array[i]] += 1;
    }

    // process auxiliry array so that aux[i] = |{k <= i}| when
    // k is the value in input array
    for (int i=1; i < k; i++)
    {
        aux[i] += aux[i-1];
    }

    // use aux to get output. This step is a little tricky,
    // need to pay more attention on this. Be careful that
    // values in aux is the count, here we need indexes start
    // from 0, so aux[array[i]] need to minus 1
    for (int i=size-1; i >= 0; i--)
    {
        output[aux[array[i]] - 1] = array[i];
        aux[array[i]] -= 1;
    }

    // copy output into original input array
    for (int i=0; i < size; i++)
    {
        array[i] = output[i];
    }
}

int main(int argc, char** argv)
{
    int a[] = {5,4,1,8,9,2,3,0,7,4,2,6,9};
    vector<int> input(a, a + sizeof(a) / sizeof(a[0]));
    cout << "input:  ";
    print(input);
    sort(input);
    cout << "output: ";
    print(input);
}
