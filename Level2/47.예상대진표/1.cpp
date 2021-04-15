// 0.01ms
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    double da = double(a), db = double(b);
    int cnt = 0;
    while (true)
    {
        cnt++;
        da = ceil(da / 2);
        db = ceil(db / 2);
        if (da == db)
        {
            return cnt;
        }
    }
}