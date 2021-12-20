#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(string begin, string target, vector<string> words) {
  queue<pair<string, int>> q;
  q.push({begin, 0});

  while (!q.empty()) {
    string curr = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (cnt > words.size()) return 0;

    if (curr == target) return cnt;

    for (int i = 0; i < words.size(); i++) {
      string next = words[i];
      if (curr == next) continue;

      int diff = 0;
      for (int j = 0; j < begin.length(); j++) {
        if (curr[j] != next[j]) diff++;
        if (diff >= 2) break;
      }
      if (diff == 1) {
        q.push({next, cnt + 1});
      }
    }
  }

  return 0;
}