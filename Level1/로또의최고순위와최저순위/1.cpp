#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;
  int correct = 0, zero = 0;
  for (int i = 0; i < 6; i++) {
    if (lottos[i] == 0) {
      zero++;
      continue;
    }
    for (int j = 0; j < 6; j++) {
      if (lottos[i] == win_nums[j]) {
        correct++;
        break;
      }
    }
  }
  int MAX = correct + zero, MIN = correct;
  answer.push_back(min(7 - MAX, 6));
  answer.push_back(min(7 - MIN, 6));
  return answer;
}