// 0.05ms
#include <string>
#include <vector>

using namespace std;

bool visit[200];

void dfs(const vector<vector<int>> &computers, int node)
{
    visit[node] = true;

    for (int i = 0; i < computers.size(); i++)
    {
        if (visit[i] || !computers[node][i])
            continue;
        dfs(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int network = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            network++;
            dfs(computers, i);
        }
    }

    return network;
}