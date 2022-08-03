#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  int n = board.size();
  stack<int> bucket;
  for (const auto &line : moves) {
    for (int j = 0; j < n; j++) {
      int &curr = board[j][line - 1];
      if (curr != 0) {
        if (!bucket.empty() && bucket.top() == curr) {
          answer += 2;
          bucket.pop();
        } else {
          bucket.push(curr);
        }
        curr = 0;
        break;
      }
    }
  }
  return answer;
}