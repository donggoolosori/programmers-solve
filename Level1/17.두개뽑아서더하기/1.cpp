#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool visit[201];

vector<int> solution(vector<int> numbers) {
  vector<int> answer;
  for (int i = 0; i < numbers.size(); i++) {
    for (int j = i + 1; j < numbers.size(); j++) {
      int sum = numbers[i] + numbers[j];
      if (visit[sum]) continue;
      visit[sum] = true;
      answer.push_back(sum);
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}