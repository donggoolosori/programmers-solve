#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct compare {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    return a[1] > b[1];
  }
};

int solution(vector<vector<int>> jobs) {
  int answer = 0;
  sort(jobs.begin(), jobs.end());

  priority_queue<vector<int>, vector<vector<int>>, compare> pq;

  int sum = 0, curT = 0, index = 0;

  while (index < jobs.size() || !pq.empty()) {
    if (jobs.size() > index && curT >= jobs[index][0]) {
      pq.push(jobs[index++]);
      continue;
    }
    if (!pq.empty()) {
      curT += pq.top()[1];
      answer += curT - pq.top()[0];
      pq.pop();
    } else
      curT = jobs[index][0];
  }
  return answer / jobs.size();
}