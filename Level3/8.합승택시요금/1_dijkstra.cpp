// 실패 - 접근부터 틀림
// 다익스트라로 접근해봤지만 모든 경유지의 경우를 생각해봐야 하므로
// 플로이드 워셜이 맞을 것 같다.
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 987654321;
int dist[201];
struct Node
{
    int idx, cost;
    bool operator<(const Node &b) const
    {
        return cost > b.cost;
    }
};
vector<Node> graph[201];

void dijkstra(int s)
{
    dist[s] = 0;
    priority_queue<Node> pq;
    pq.push({s, 0});

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        for (const auto &next : graph[curr.idx])
        {
            int nextCost = curr.cost + next.cost;
            if (dist[next.idx] > nextCost)
            {
                dist[next.idx] = nextCost;
                pq.push({next.idx, nextCost});
            }
        }
    }
}

void setGraph(vector<vector<int>> &fares)
{
    for (const auto &fare : fares)
    {
        int a = fare[0], b = fare[1], cost = fare[2];
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
}
void initDist(int n)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INF;
    setGraph(fares);

    // 출발지 -> A , 출발지 -> B
    initDist(n);
    dijkstra(s);
    int cand1 = dist[a], cand2 = dist[b];

    // A -> B
    initDist(n);
    dijkstra(a);
    cand1 += dist[s];
    // B -> A
    initDist(n);
    dijkstra(b);
    cand1 += dist[a];

    answer = min(cand1, cand2);
    cout << cand1 << ' ' << cand2 << '\n';
    return answer;
}