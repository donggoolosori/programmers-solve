#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
  vector<int> answer;
  if (divisor == 1) {
    answer = arr;
  } else {
    for (const auto &num : arr) {
      if (num % divisor == 0) answer.push_back(num);
    }
  }
  if (answer.empty()) {
    return {-1};
  }
  sort(answer.begin(), answer.end());
  return answer;
}