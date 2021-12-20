#include <string>
#include <vector>

using namespace std;

int visit[200];

void dfs(vector<vector<int>> &computers, int fr, int to) {
  visit[to] = true;
  for (int i = 0; i < computers[to].size(); i++) {
    if (visit[i] || computers[to][i] == 0) continue;
    dfs(computers, to, i);
  }
}

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (visit[i]) continue;
    for (int j = 0; j < n; j++) {
      if (computers[i][j] == 0 || visit[j]) continue;
      answer++;
      visit[i] = true;
      dfs(computers, i, j);
    }
  }

  return answer;
}