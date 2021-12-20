#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
  int answer = 0;
  int d[500][500] = {0};
  int n = triangle.size();
  d[0][0] = triangle[0][0];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      d[i][j] = max(d[i][j], d[i - 1][j] + triangle[i][j]);
      if (j > 0) d[i][j] = max(d[i][j], d[i - 1][j - 1] + triangle[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    answer = max(answer, d[n - 1][i]);
  }

  return answer;
}