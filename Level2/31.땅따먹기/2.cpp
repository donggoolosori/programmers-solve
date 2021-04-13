/*
14.24ms
top down 방식
N이 작은 경우 2번 풀이가 1번 풀이보다 7배 정도 빠르지만 N이 커지면 별 차이가 없다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100000][4];

int findMaxScore(int y, int x, const vector<vector<int>> &land)
{
    if (y == 0)
        return land[y][x];
    int &ret = cache[y][x];
    if (ret != 0)
        return ret;
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i == x)
            continue;
        temp = max(temp, findMaxScore(y - 1, i, land));
    }
    return ret = land[y][x] + temp;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int n = land.size();

    for (int i = 0; i < 4; i++)
        answer = max(answer, findMaxScore(n - 1, i, land));

    return answer;
}