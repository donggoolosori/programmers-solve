#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
  vector<int> answer;
  multiset<int> ms;

  for (string s : operations) {
    // insert
    if (s[0] == 'I') {
      ms.insert(stoi(s.substr(2)));
    } else {
      // 최댓값 삭제
      if (stoi(s.substr(2)) == 1) {
        if (!ms.empty()) ms.erase(--ms.end());
      }
      // 최솟값 삭제
      else {
        if (!ms.empty()) ms.erase(ms.begin());
      }
    }
  }
  if (ms.empty())
    answer.assign({0, 0});
  else {
    answer.push_back(*(--ms.end()));
    answer.push_back(*ms.begin());
  }

  return answer;
}