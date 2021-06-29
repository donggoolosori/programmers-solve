// 시간초과
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> burst;
bool isBursted[1000000];

void dfs(vector<int> &a, int remains, int l_idx, int b_idx, bool chance) {
  if (remains == 1) {
    burst.insert(a[l_idx]);
    return;
  }

  for (int i = 0; i < a.size() - 1; i++) {
    if (isBursted[i]) continue;
    int j = i + 1;
    while (j < a.size() && isBursted[j]) j++;
    if (j == a.size()) return;
    int left = a[i], right = a[j];
    int smaller = i, bigger = j;

    if (left > right) swap(smaller, bigger);

    if (chance) {
      isBursted[smaller] = true;
      dfs(a, remains - 1, bigger, smaller, false);
      isBursted[smaller] = false;
    }
    isBursted[bigger] = true;
    dfs(a, remains - 1, smaller, bigger, chance);
    isBursted[bigger] = false;
  }
}

int solution(vector<int> a) {
  dfs(a, a.size(), 0, 0, true);

  return burst.size();
}