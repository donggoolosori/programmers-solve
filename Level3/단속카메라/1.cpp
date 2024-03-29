#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
  int answer = 0;
  sort(routes.begin(), routes.end());

  for (int i = 0; i < routes.size(); i++) {
    answer++;
    int s = routes[i][0], e = routes[i][1];
    int j;
    for (j = i + 1; j < routes.size(); j++) {
      int ns = routes[j][0], ne = routes[j][1];

      s = max(s, ns);
      e = min(e, ne);
      if (s > e) {
        j--;
        break;
      }
    }
    i = j;
  }

  return answer;
}