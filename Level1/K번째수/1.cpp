#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  for (const auto &command : commands) {
    int i = command[0], j = command[1], k = command[2];
    vector<int> newArr;
    newArr.assign(array.begin() + i - 1, array.begin() + j);
    sort(newArr.begin(), newArr.end());
    answer.push_back(newArr[k - 1]);
  }

  return answer;
}