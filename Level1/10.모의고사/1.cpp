#include <string>
#include <vector>

using namespace std;

int way1[5] = {1, 2, 3, 4, 5};
int way2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int way3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
  vector<int> cnt(4);

  for (int i = 0; i < answers.size(); i++) {
    if (way1[i % 5] == answers[i]) cnt[1]++;
    if (way2[i % 8] == answers[i]) cnt[2]++;
    if (way3[i % 10] == answers[i]) cnt[3]++;
  }

  int MAX = max(cnt[1], max(cnt[2], cnt[3]));

  vector<int> answer;
  for (int i = 1; i <= 3; i++) {
    if (MAX == cnt[i]) {
      answer.push_back(i);
    }
  }
  return answer;
}