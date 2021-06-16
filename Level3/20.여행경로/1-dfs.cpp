#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ans = "";
string made = "";
bool visit[10001];

bool compare(vector<string> a, vector<string> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}

void dfs(vector<vector<string>> &tickets, int L) {
  if (ans != "" && made > ans) return;

  if (L == tickets.size()) {
    if (ans == "" || made < ans) ans = made;
    return;
  }

  for (int i = 0; i < tickets.size(); i++) {
    if (visit[i]) continue;
    if (tickets[i][0] != made.substr(made.size() - 3, 3)) continue;

    visit[i] = true;
    made += tickets[i][1];

    dfs(tickets, L + 1);

    visit[i] = false;
    made = made.substr(0, made.size() - 3);
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  sort(tickets.begin(), tickets.end(), compare);

  for (int i = 0; i < tickets.size(); i++) {
    if (tickets[i][0] != "ICN") continue;
    made = tickets[i][0] + tickets[i][1];
    visit[i] = true;
    dfs(tickets, 1);
    visit[i] = false;
  }
  vector<string> ret;

  for (int i = 0; i < ans.size(); i += 3) {
    ret.push_back(ans.substr(i, 3));
  }

  return ret;
}