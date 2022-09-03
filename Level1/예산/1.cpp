#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
  int answer = 0, sum = 0;
  sort(d.begin(), d.end());
  for (int i = 0; i < d.size(); i++) {
    if (sum + d[i] > budget) break;
    sum += d[i];
    answer++;
  }
  return answer;
}