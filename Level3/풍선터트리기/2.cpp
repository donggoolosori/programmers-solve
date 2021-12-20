#include <string>
#include <vector>
#define MAX 1000000
using namespace std;

int l_smallest[MAX];
int r_smallest[MAX];

int solution(vector<int> a) {
  int answer = 0;

  int MIN = 1e9;
  for (int i = 0; i < a.size(); i++) {
    MIN = min(MIN, a[i]);
    l_smallest[i] = MIN;
  }
  MIN = 1e9;
  for (int i = a.size() - 1; i >= 0; i--) {
    MIN = min(MIN, a[i]);
    r_smallest[i] = MIN;
  }

  for (int i = 0; i < a.size(); i++) {
    if (i == 0 || i == a.size() - 1) {
      answer++;
      continue;
    }
    int curr = a[i];
    if (curr > l_smallest[i - 1] && curr > r_smallest[i + 1]) continue;
    answer++;
  }
  return answer;
}