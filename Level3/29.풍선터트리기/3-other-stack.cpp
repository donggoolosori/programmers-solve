#include <stack>
#include <string>
#include <vector>

using namespace std;
int solution(vector<int> a) {
  int answer = a.size();
  stack<int> stk;
  for (const auto &el : a) {
    while (!stk.empty() && el < stk.top()) {
      stk.pop();
      if (!stk.empty()) answer--;
    }
    stk.push(el);
  }
  return answer;
}
