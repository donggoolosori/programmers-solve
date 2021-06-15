// dfs
// 시간초과
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int N;
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
bool visit[25][25];

int getMinCost(vector<vector<int>> &board, int y, int x, bool vertical) {
  if (y == 0 && x == 0) return 0;

  int MIN = 1e9;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
    if (visit[ny][nx]) continue;
    if (board[ny][nx] == 1) continue;

    visit[ny][nx] = true;

    if (y == N - 1 && x == N - 1) {
      if (dy[i] == 0)
        MIN = min(MIN, getMinCost(board, ny, nx, false) + 100);
      else
        MIN = min(MIN, getMinCost(board, ny, nx, true) + 100);
    }

    if (vertical) {
      if (dx[i] == 0)
        MIN = min(MIN, getMinCost(board, ny, nx, true) + 100);
      else
        MIN = min(MIN, getMinCost(board, ny, nx, false) + 600);
    } else {
      if (dy[i] == 0)
        MIN = min(MIN, getMinCost(board, ny, nx, false) + 100);
      else
        MIN = min(MIN, getMinCost(board, ny, nx, true) + 600);
    }
    visit[ny][nx] = false;
  }
  return MIN;
}

int solution(vector<vector<int>> board) {
  N = board.size();

  return getMinCost(board, N - 1, N - 1, false);
}