#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 20001

using namespace std;

const int INF = 2e9;

struct Node {
  int idx, dist;
  bool operator<(const Node &b) const { return dist > b.dist; }
};

int solution(int n, vector<vector<int>> edge) {
  int answer = 0, maxDist = 0;

  priority_queue<Node> pq;
  int cache[MAX];
  for (int i = 1; i <= n; i++) cache[i] = INF;
  vector<int> graph[MAX];

  for (const auto &el : edge) {
    int a = el[0], b = el[1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  cache[1] = 0;
  pq.push({1, 0});
  while (!pq.empty()) {
    int idx = pq.top().idx;
    int dist = pq.top().dist;
    pq.pop();

    if (dist > cache[idx]) continue;

    for (const auto &next : graph[idx]) {
      if (dist + 1 >= cache[next]) continue;

      cache[next] = dist + 1;
      pq.push({next, dist + 1});

      if (cache[next] > maxDist) maxDist = cache[next];
    }
  }
  for (int i = 2; i <= n; i++) {
    if (cache[i] == maxDist) answer++;
  }

  return answer;
}