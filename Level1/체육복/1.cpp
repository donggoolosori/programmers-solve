#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  unordered_map<int, int> um;
  for (int i = 1; i <= n; i++) {
    um[i] = 1;
  }
  for (const auto &l : lost) {
    um[l]--;
  }
  for (const auto &r : reserve) {
    um[r]++;
  }

  int answer = 0;
  for (int i = 1; i <= n; i++) {
    if (um[i] >= 1) {
      answer++;
    } else {
      if (i > 0 && um[i - 1] == 2) {
        answer++;
        um[i - 1]--;
        continue;
      }
      if (i < n && um[i + 1] == 2) {
        answer++;
        um[i + 1]--;
        continue;
      }
    }
  }
  return answer;
}