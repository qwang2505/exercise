/**
 * Radix sort.
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "../basic/util.h"

using namespace std;

int maxNum(vector<int> array)
{
    int m = 0;
    for (int i=0; i < array.size(); i++)
    {
        if (array[i] > m)
        {
            m = array[i];
        }
    }
    return m;
}

int getRound(vector<int> array, int bitSize)
{
    int round = 0;
    int max = maxNum(array);
    while (max > 0)
    {
        max = max >> bitSize;
        round += 1;
    }
    return round;
}

int getDigit(int value, int bitSize, int round)
{
    int mask = (int)pow(2, bitSize) - 1;
    mask = mask << (round * bitSize);
    value = value & mask;
    return value >> (round * bitSize);
}

void radixSort(vector<int> &array, int bitSize, int round)
{
    int size = (int)pow(2, bitSize);
    cout << "aux size: " << size << endl;
    int digit;
    vector<int> aux(size, 0);
    for (int i=0; i < array.size(); i++)
    {
        digit = getDigit(array[i], bitSize, round);
        aux[digit] += 1;
    }

    for (int i=1; i < aux.size(); i++)
    {
        aux[i] += aux[i-1];
    }

    vector<int> output(array.size());
    int order;
    for (int i=array.size()-1; i >= 0; i--)
    {
        digit = getDigit(array[i], bitSize, round);
        order = aux[digit] - 1;
        output[order] = array[i];
        aux[digit] -= 1;
    }

    for (int i=0; i < array.size(); i++)
    {
        array[i] = output[i];
    }
}

void sort(vector<int> &array, int bitSize)
{
    // get round need to run based on the given bit size
    // Time = O(n), Space = O(1)
    int round = getRound(array, bitSize);
    cout << "round: " << round << endl;

    for (int i=0; i < round; i++)
    {
        radixSort(array, bitSize, i);
    }
}

int main(int argc, char** argv)
{
    // set seed of random numbers
    srand((int)time(0));

    // generate randomized input integers
    vector<int> array;
    randomVector(array, 20000000);

    long start = getTime();
    cout << "start sort" << endl;
    sort(array, 16);
    cout << "spend: " << getTime() - start << "ms." << endl;
}
