#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
  multiset<int> mts;

  // initialize
  for (int i = 0; i < k; i++) {
    mts.insert(stones[i]);
  }
  int low = 0;
  int answer = *mts.rbegin();

  for (int i = k; i < stones.size(); i++) {
    mts.erase(mts.find(stones[low]));
    low++;

    mts.insert(stones[i]);

    answer = min(answer, *mts.rbegin());
  }

  return answer;
}