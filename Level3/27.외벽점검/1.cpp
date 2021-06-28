#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

bool check(int &n, vector<int> &weak, vector<int> &dist) {
  deque<int> c_weak(weak.begin(), weak.end());
  for (int i = 0; i < c_weak.size(); i++) {
    int idx = 0;

    for (int j = 0; j < dist.size(); j++) {
      int start = c_weak[idx];
      int end = c_weak[idx] + dist[j];
      while (idx < c_weak.size() && c_weak[idx] <= end) idx++;

      if (idx == c_weak.size()) return true;
    }

    c_weak.push_back(n + c_weak.front());
    c_weak.pop_front();
  }

  return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
  int answer = 0;
  sort(dist.begin(), dist.end(), greater<int>());

  // 검사자 인원 1~ 최대 까지
  for (int i = 1; i <= dist.size(); i++) {
    vector<int> c_dist(dist.begin(), dist.begin() + i);
    // 검사하는 친구의 순서 정하기
    do {
      if (check(n, weak, c_dist)) return i;
    } while (prev_permutation(c_dist.begin(), c_dist.end()));
  }

  return -1;
}