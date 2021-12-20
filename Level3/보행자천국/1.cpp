#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;
int M, N;
int dy[] = {0, 1}, dx[] = {1, 0};
int cache[500][500][2];

int getAllWays(vector<vector<int>> &city_map, int y, int x, int dir) {
  if (y == M - 1 && x == N - 1) return 1;

  int &ret = cache[y][x][dir];
  if (ret != -1) return ret;

  int cnt = 0;
  for (int i = 0; i < 2; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= M || nx >= N) continue;
    if (city_map[ny][nx] == 1) continue;
    if (city_map[y][x] == 2 && dir != i) continue;

    cnt += getAllWays(city_map, ny, nx, i);
  }

  return ret = cnt % MOD;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
  M = m, N = n;
  memset(cache, -1, sizeof(cache));

  int answer = getAllWays(city_map, 0, 0, 0);

  return answer;
}