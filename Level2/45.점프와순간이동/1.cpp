// 0.01ms
#include <iostream>
#include <algorithm>

using namespace std;

int findMinBattery(int index, int usage)
{
    if (index == 0)
        return usage;
    if (index % 2 == 0)
        return findMinBattery(index / 2, usage);
    else
        return findMinBattery(index - 1, usage + 1);
}

int solution(int n)
{
    return findMinBattery(n, 0);
}