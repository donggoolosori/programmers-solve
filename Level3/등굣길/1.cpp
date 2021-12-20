#include <string>
#include <vector>

using namespace std;

int cache[101][101];

int getCases(int y, int x) {
  if (cache[y][x] == -1 || y == 0 || x == 0) return 0;
  if (y == 1 && x == 1) return 1;

  int &ret = cache[y][x];
  if (ret != 0) return ret;

  return ret = (getCases(y - 1, x) + getCases(y, x - 1)) % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
  for (const auto &puddle : puddles) {
    cache[puddle[1]][puddle[0]] = -1;
  }

  return getCases(n, m);
}