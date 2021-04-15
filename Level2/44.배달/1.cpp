// 0.28ms
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> maps[51];
vector<int> minCost(51, INF);

void dijkstra()
{
    // pair<cost, first>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    minCost[1] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (minCost[curr] < cost)
            continue;

        for (int i = 0; i < maps[curr].size(); i++)
        {
            int next = maps[curr][i].second;
            int nextCost = cost + maps[curr][i].first;

            if (nextCost < minCost[next])
            {
                minCost[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    // maps 초기화
    for (const auto &i : road)
    {
        int fr = i[0], to = i[1], w = i[2];
        maps[fr].push_back({w, to});
        maps[to].push_back({w, fr});
    }
    // 다익스트라 알고리즘으로 1번에서 각 노드까지의 최단경로 계산
    dijkstra();
    // 최단경로가 K 이하이면 answer+1
    for (int i = 1; i <= N; i++)
    {
        if (minCost[i] <= K)
            answer++;
    }

    return answer;
}