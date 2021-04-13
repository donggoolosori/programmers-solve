// 0.13ms
#include <string>
#include <vector>

using namespace std;

int getRangeSum(int from, int to)
{
    int len = to - from + 1;
    int ret = (from + to) * (len / 2);
    if (len % 2 == 0)
        return ret;
    return ret + (from + to) / 2;
}

int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int curr = getRangeSum(i, j);
            if (curr > n)
                break;
            if (curr == n)
                answer++;
        }
    }
    return answer;
}