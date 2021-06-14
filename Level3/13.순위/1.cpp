#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int graph[101][101];

int solution(int n, vector<vector<int>> results) {
  int answer = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      graph[i][j] = 1e9;
    }
  }

  for (const auto &result : results) {
    int winner = result[0], loser = result[1];
    graph[winner][loser] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] != 1e9 || graph[j][i] != 1e9) cnt++;
    }
    if (cnt == n) answer++;
  }

  return answer;
}