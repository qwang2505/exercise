#include <iostream>
#include <vector>

using namespace std;

/**
 * 交换vector中指定两个索引位置的值
 */
void exch(vector<int> &array, int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

/**
 * 切分vector中指定的子数组，这里使用子数组的第一个位置的值作为切分标准
 */
int partition(vector<int> &array, int start, int end)
{
    // 如果已经只剩一个元素了，没必要继续拆分
    if (start >= end)
    {
        return -1;
    }
    // 选择pivot
    int pivot = array[start];
    int index = start;
    int temp;
    // 从指定位置的下一个位置开始，将比pivot小的元素交换到其左边
    // 注意交换的位置是index++
    // 这样，在任何时候，从start+1到index的元素均小于pivot
    for (int i=start+1; i <= end; i++)
    {
        if (array[i] <= pivot)
        {
            index++;
            exch(array, index, i);
        }
    }
    // 交换pivot和最终的index位置的元素，这样pivot就位于中间了
    exch(array, start, index);
    // 返回切分后中间位置，也就是pivot所在位置的索引
    return index;
}

/**
 * 进行快速排序
 */
void sort(vector<int> &array, int start, int end)
{
    // 先进行切分
    int r = partition(array, start, end);
    // 如果切分返回小于0，说明没有切分，也无需对子数组进行递归排序
    if (r >= 0)
    {
        // 分别对切分后的两个子数组进行递归排序
        sort(array, start, r - 1);
        sort(array, r + 1, end);
    }
}

int main(int argc, char** argv)
{
    // 注意数组的初始化方法
    int a[] = {5,9,10,12,54,2,3,15};
    // 注意vector的初始化方法
    vector<int> array(a, a + sizeof(a)/sizeof(a[0]));
    // 传递引用，以便在内部修改
    sort(array, 0, array.size() - 1);
    for (int i=0; i < array.size(); i++)
    {
        cout << array[i] << "->";
    }
    cout << endl;
}
