#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int req_time, run_time;
  bool operator<(const Node &b) const { return run_time > b.run_time; }
};

int solution(vector<vector<int>> jobs) {
  priority_queue<Node> pq;
  sort(jobs.begin(), jobs.end());

  int idx = 0, time = 0, sum = 0;

  while (idx < jobs.size() || !pq.empty()) {
    if (idx < jobs.size() && jobs[idx][0] <= time) {
      pq.push({jobs[idx][0], jobs[idx][1]});
      idx++;
      continue;
    }

    if (!pq.empty()) {
      time += pq.top().run_time;
      sum += time - pq.top().req_time;
      pq.pop();
    } else {
      time = jobs[idx][0];
    }
  }

  int answer = sum / jobs.size();
  return answer;
}