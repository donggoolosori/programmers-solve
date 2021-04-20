// 2.36ms
#include <string>
#include <vector>

using namespace std;

int visit[201];

void dfs(vector<vector<int>> computers, int n, int index)
{
    visit[index] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && computers[index][i])
            dfs(computers, n, i);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            answer++;
            dfs(computers, n, i);
        }
    }
    return answer;
}