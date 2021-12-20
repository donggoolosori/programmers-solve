#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
  vector<int> answer(2);
  unordered_map<string, int> gemCount;

  for (int i = 0; i < gems.size(); i++) {
    gemCount[gems[i]]++;
  }

  int low = 0, high = gems.size() - 1;
  while (true) {
    string gem = gems[high];

    if (gemCount[gem] >= 2) {
      gemCount[gem]--;
      high--;
    } else
      break;
  }
  int minDist = high - low;
  answer[0] = low + 1, answer[1] = high + 1;

  while (high < gems.size()) {
    string l_gem = gems[low];
    gemCount[l_gem]--;
    low++;

    if (gemCount[l_gem] == 0) {
      while (++high < gems.size()) {
        gemCount[gems[high]]++;
        if (l_gem == gems[high]) break;
      }
      if (high == gems.size()) break;
    }
    if (minDist > high - low) {
      answer[0] = low + 1;
      answer[1] = high + 1;
      minDist = high - low;
    }
  }

  return answer;
}