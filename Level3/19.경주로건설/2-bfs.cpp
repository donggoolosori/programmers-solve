#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int y, x, dir, cost;
};
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int solution(vector<vector<int>> board) {
  int answer = 1e9;
  int n = board.size();
  vector<vector<int>> costs(n, vector<int>(n, 1e9));
  queue<Node> q;
  q.push({0, 0, -1, 0});

  while (!q.empty()) {
    Node curr = q.front();
    int y = curr.y, x = curr.x, cost = curr.cost, dir = curr.dir;
    q.pop();

    if (y == n - 1 && x == n - 1) {
      answer = min(answer, cost);
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if (board[ny][nx] == 1) continue;

      int next_cost = 0;
      if (dir == -1 || dir == i)
        next_cost = cost + 100;
      else
        next_cost = cost + 600;

      if (costs[ny][nx] >= next_cost) {
        costs[ny][nx] = next_cost;
        q.push({ny, nx, i, next_cost});
      }
    }
  }

  return answer;
}