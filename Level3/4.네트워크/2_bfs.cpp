// 0.17ms
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visit[200];

void bfs(int node, const vector<vector<int>> &computers)
{
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int curr = q.front();
        visit[curr] = true;
        q.pop();

        for (int i = 0; i < computers.size(); i++)
        {
            if (visit[i] || !computers[curr][i])
                continue;
            q.push(i);
        }
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
            bfs(i, computers);
        }
    }
    return answer;
}