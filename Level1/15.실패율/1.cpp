#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int stage;
  double fail_ratio;
  bool operator<(const Node &b) const {
    if (fail_ratio == b.fail_ratio) {
      return stage < b.stage;
    }
    return fail_ratio > b.fail_ratio;
  }
};

vector<int> solution(int N, vector<int> stages) {
  vector<Node> fail;
  vector<int> answer;
  sort(stages.begin(), stages.end());

  for (int stage = 1; stage <= N; stage++) {
    double challenger = 0;
    double failure = 0;

    for (int i = 0; i < stages.size(); i++) {
      if (stages[i] < stage) continue;
      if (stage == stages[i]) failure++;
      challenger++;
    }
    double fail_ratio;
    if (challenger == 0) {
      fail_ratio = 0;
    } else {
      fail_ratio = failure / challenger;
    }
    fail.push_back({stage, fail_ratio});
  }
  sort(fail.begin(), fail.end());
  for (const auto &f : fail) {
    answer.push_back(f.stage);
  }
  return answer;
}