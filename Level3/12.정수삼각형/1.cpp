#include <cstring>
#include <string>
#include <vector>

using namespace std;

int cache[501][501];
int n;

int getMaxSum(const vector<vector<int>> &triangle, int y, int x) {
  if (y == n - 1) return triangle[y][x];

  int &ret = cache[y][x];
  if (ret != -1) return ret;

  return ret = triangle[y][x] + max(getMaxSum(triangle, y + 1, x),
                                    getMaxSum(triangle, y + 1, x + 1));
}

int solution(vector<vector<int>> triangle) {
  n = triangle.size();
  memset(cache, -1, sizeof(cache));

  return getMaxSum(triangle, 0, 0);
}