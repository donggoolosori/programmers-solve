// 14.41ms
// bottom up 방식
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[100000][4];
int n;
int findMax(int y, int x, vector<vector<int>> &land)
{
    // 기저사례
    if (y == n - 1)
        return land[y][x];
    // 메모이제이션
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    int tempMax = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i == x)
            continue;
        tempMax = max(tempMax, findMax(y + 1, i, land));
    }
    return cache[y][x] = land[y][x] + tempMax;
}

int solution(vector<vector<int>> land)
{
    n = land.size();

    memset(cache, -1, sizeof(cache));
    int answer = 0;
    for (int i = 0; i < 4; i++)
        answer = max(answer, findMax(0, i, land));
    return answer;
}