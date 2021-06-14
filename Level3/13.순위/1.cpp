#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool graph[101][101];

int solution(int n, vector<vector<int>> results) {
  int answer = 0;

  for (const auto &result : results) {
    int winner = result[0], loser = result[1];
    graph[winner][loser] = true;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (graph[i][k] && graph[k][j]) graph[i][j] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] || graph[j][i]) cnt++;
    }
    if (cnt == n - 1) answer++;
  }

  return answer;
}