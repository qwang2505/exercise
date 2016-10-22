#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, int start1, int end1, int start2, int end2, vector<int> &aux)
{
    int i = start1, j = start2, p = start1;
    while (i <= end1 || j <= end2)
    {
        if (i > end1)
        {
            aux[p++] = array[j++];
            continue;
        }
        if (j > end2)
        {
            aux[p++] = array[i++];
            continue;
        }
        if (array[i] <= array[j])
        {
            aux[p++] = array[i++];
            continue;
        }
        else
        {
            aux[p++] = array[j++];
            continue;
        }
    }
    for (int m=start1; m < p; m++)
    {
        array[m] = aux[m];
        aux[m] = -1;
    }
}

void sort(vector<int> &array, int start, int end, vector<int> &aux)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    sort(array, start, mid, aux);
    sort(array, mid + 1, end, aux);
    merge(array, start, mid, mid+1, end, aux);
}

int main(int argc, char** argv) 
{
    // 初始化方式
    int a[] = {5,2,4,7,0,19,4,6,28};
    vector<int> input(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> aux(input.size(), -1);
    // 需要辅助vector来进行合并
    sort(input, 0, input.size() - 1, aux);
    for (int i=0; i < input.size(); i++)
    {
        cout << input[i] << "->";
    }
    cout << endl;
}
