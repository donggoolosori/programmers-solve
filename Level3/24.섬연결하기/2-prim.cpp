/*
크루스칼보다 빨랐다.
정점보다 간선의 개수가 많아서 그런 듯
*/
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int idx, cost;
  bool operator<(const Node &b) const { return cost > b.cost; }
};
vector<Node> graph[101];
bool visit[101];

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;
  for (int i = 0; i < costs.size(); i++) {
    int a = costs[i][0], b = costs[i][1], c = costs[i][2];
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  priority_queue<Node> pq;
  for (const auto &next : graph[0]) {
    pq.push({next.idx, next.cost});
  }
  visit[0] = true;
  while (!pq.empty()) {
    int idx = pq.top().idx, cost = pq.top().cost;
    pq.pop();

    if (visit[idx]) continue;
    visit[idx] = true;
    answer += cost;

    for (const auto &next : graph[idx]) {
      if (visit[next.idx]) continue;
      pq.push({next.idx, next.cost});
    }
  }

  return answer;
}