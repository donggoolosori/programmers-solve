#include <string>
#include <vector>

using namespace std;

bool building[101][101][2];
int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1},
    dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool checkPilar(int y, int x, int n) {
  if ((y == 0) || (building[y][x][1]) ||
      (x - 1 >= 0 && building[y][x - 1][1]) ||
      (y - 1 >= 0 && building[y - 1][x][0]))
    return true;
  return false;
}

bool checkBo(int y, int x, int n) {
  if ((y - 1 >= 0 && building[y - 1][x][0]) ||
      (x + 1 <= n && y - 1 >= 0 && building[y - 1][x + 1][0]) ||
      (x + 1 <= n && x - 1 >= 0 && building[y][x + 1][1] &&
       building[y][x - 1][1]))
    return true;
  return false;
}

bool isValid(int y, int x, int n) {
  for (int i = 0; i < 9; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

    if (building[ny][nx][0] && !checkPilar(ny, nx, n)) return false;
    if (building[ny][nx][1] && !checkBo(ny, nx, n)) return false;
  }

  return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
  vector<vector<int>> answer;

  for (const auto &bf : build_frame) {
    int x = bf[0], y = bf[1], kind = bf[2], method = bf[3];

    building[y][x][kind] = method;
    if (!isValid(y, x, n)) building[y][x][kind] = !method;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
        if (building[j][i][k]) answer.push_back({i, j, k});
      }
    }
  }

  return answer;
}