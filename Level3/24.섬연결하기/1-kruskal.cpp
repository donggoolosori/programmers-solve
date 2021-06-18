#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int parent[101];

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  parent[b] = a;
}

bool compareParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b)
    return true;
  else
    return false;
}

bool compare(vector<int> a, vector<int> b) { return a[2] < b[2]; }

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;
  sort(costs.begin(), costs.end(), compare);

  for (int i = 0; i < n; i++) parent[i] = i;

  for (const auto &cost : costs) {
    int a = cost[0], b = cost[1], c = cost[2];

    if (compareParent(a, b)) continue;
    unionParent(a, b);
    answer += c;
  }

  return answer;
}