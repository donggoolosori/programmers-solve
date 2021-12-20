#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int cache[20001];
int maxDist;
vector<int> graph[20001];
struct Node {
  int idx, dist;
  bool operator<(const Node &b) const { return dist > b.dist; }
};

void dijkstra() {
  priority_queue<Node> pq;

  cache[1] = 0;
  pq.push({1, 0});

  while (!pq.empty()) {
    int curr = pq.top().idx;
    int dist = pq.top().dist;
    pq.pop();

    if (dist > cache[curr]) continue;

    for (const auto &next : graph[curr]) {
      if (dist + 1 >= cache[next]) continue;

      cache[next] = dist + 1;
      pq.push({next, dist + 1});

      if (cache[next] > maxDist) maxDist = cache[next];
    }
  }
}

int solution(int n, vector<vector<int>> edge) {
  int answer = 0;
  for (int i = 0; i < edge.size(); i++) {
    int a = edge[i][0], b = edge[i][1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) cache[i] = 2e9;
  dijkstra();
  for (int i = 2; i <= n; i++) {
    if (cache[i] == maxDist) answer++;
  }

  return answer;
}