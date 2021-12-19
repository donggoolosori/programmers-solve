#include <queue>
#include <string>
#include <vector>

#define INF 987654321
#define MAX 20000

using namespace std;

struct Node {
  int idx, dist;
  bool operator<(const Node &b) const { return dist > b.dist; }
};
vector<int> graph[MAX + 1];
int cache[MAX + 1], maxDist;

void dijkstra() {
  priority_queue<Node> pq;
  pq.push({1, 0});
  cache[1] = 0;

  while (!pq.empty()) {
    int curr = pq.top().idx, dist = pq.top().dist;
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
  for (const auto &e : edge) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  for (int i = 0; i <= n; i++) cache[i] = INF;

  dijkstra();

  int answer = 0;
  for (int i = 2; i <= n; i++) {
    if (cache[i] == maxDist) answer++;
  }
  return answer;
}