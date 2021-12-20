#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ans = "";
bool visit[10001];

bool compare(vector<string> a, vector<string> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}

void dfs(vector<vector<string>> &tickets, int L, string curr, string path) {
  if (ans != "" && path > ans) return;

  if (L == tickets.size()) {
    if (ans == "" || path < ans) ans = path;
    return;
  }

  for (int i = 0; i < tickets.size(); i++) {
    if (visit[i]) continue;
    if (tickets[i][0] != curr) continue;

    visit[i] = true;
    dfs(tickets, L + 1, tickets[i][1], path + tickets[i][1]);
    visit[i] = false;
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  sort(tickets.begin(), tickets.end(), compare);

  dfs(tickets, 0, "ICN", "ICN");

  vector<string> ret;
  for (int i = 0; i < ans.size(); i += 3) ret.push_back(ans.substr(i, 3));

  return ret;
}