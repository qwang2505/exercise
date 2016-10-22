#include <iostream>
#include <vector>

using namespace std;

void exch(vector<int> &array, int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void sort(vector<int> &array)
{
    for (int i=1; i < array.size(); i++)
    {
        for (int j=i; j > 0; j--)
        {
            if (array[j] < array[j-1])
            {
                exch(array, j, j-1);
            }
            else
            {
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int a[] = {5,3,7,91,2,3,1,10,17};
    vector<int> array(a, a + sizeof(a) / sizeof(a[0]));
    sort(array);
    for (int i=0; i < array.size(); i++)
    {
        cout << array[i] << "->";
    }
    cout << endl;
}
