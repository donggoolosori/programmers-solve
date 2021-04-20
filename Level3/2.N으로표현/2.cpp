// 1.27ms
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int answer = 9;

void dfs(const int &N, const int &number, int L, int curr)
{
    if (L > 8)
        return;
    if (curr == number)
    {
        answer = min(answer, L);
        return;
    }

    int temp = 0;
    for (int i = 1; i + L < 9; i++)
    {
        temp = temp * 10 + N;
        dfs(N, number, L + i, curr + temp);
        dfs(N, number, L + i, curr - temp);
        dfs(N, number, L + i, curr * temp);
        dfs(N, number, L + i, curr / temp);
    }
}

int solution(int N, int number)
{
    dfs(N, number, 0, 0);

    return answer > 8 ? -1 : answer;
}