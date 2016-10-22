#ifndef _UTIL_H
#define _UTIL_H

#include <time.h>
#include <vector>
#include <iostream>
#include <sys/time.h>

#define random(x) (rand() % (x))

long getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void print(std::vector<int> array)
{
    for (int i=0; i < array.size(); i++)
    {
        std::cout << array[i] << "->";
    }
    std::cout << std::endl;
}

void randomVector(std::vector<int> &array, int size, int limit = -1)
{
    srand((int)time(0));
    for (int i=0; i < size; i++)
    {
        if (limit < 0)
        {
            array.push_back(rand());
        }
        else
        {
            array.push_back(random(limit));
        }
    }
}

#endif
