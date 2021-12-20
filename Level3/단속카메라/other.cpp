#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) { return a[1] < b[1]; }

int solution(vector<vector<int>> routes) {
  int answer = 0;
  int bound = -30001;
  sort(routes.begin(), routes.end(), compare);

  for (int i = 0; i < routes.size(); i++) {
    if (bound < routes[i][0]) {
      answer++;
      bound = routes[i][1];
    }
  }

  return answer;
}