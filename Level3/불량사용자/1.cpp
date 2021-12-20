#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool visit[8];
int answer;
unordered_map<string, int> um;

bool isValid(string banned, string user) {
  int len = banned.length();

  if (len != user.length()) return false;

  for (int i = 0; i < len; i++) {
    if (banned[i] == '*') continue;
    if (banned[i] != user[i]) return false;
  }
  return true;
}

void dfs(const vector<string> &user_id, const vector<string> &banned_id, int L,
         string made) {
  if (L == banned_id.size()) {
    sort(made.begin(), made.end());
    if (um.find(made) == um.end()) answer++;
    um[made] = 1;
    return;
  }

  for (int i = 0; i < user_id.size(); i++) {
    if (visit[i]) continue;
    if (!isValid(banned_id[L], user_id[i])) continue;

    visit[i] = true;
    dfs(user_id, banned_id, L + 1, made + to_string(i));
    visit[i] = false;
  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  dfs(user_id, banned_id, 0, "");

  return answer;
}