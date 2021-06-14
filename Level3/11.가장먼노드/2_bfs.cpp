#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int cache[20001];
int maxDist;
vector<int> graph[20001];
struct Node {
  int idx, dist;
};

void bfs() {
  queue<Node> q;
  q.push({1, 1});
  cache[1] = 1;

  while (!q.empty()) {
    int curr = q.front().idx;
    int dist = q.front().dist;
    q.pop();

    for (const auto &next : graph[curr]) {
      if (cache[next] != 0) continue;

      cache[next] = dist + 1;
      q.push({next, dist + 1});
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

  bfs();
  for (int i = 2; i <= n; i++) {
    if (cache[i] == maxDist) answer++;
  }

  return answer;
}