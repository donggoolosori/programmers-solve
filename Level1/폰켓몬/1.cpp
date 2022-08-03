#include <set>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int n = nums.size();
  set<int> st(nums.begin(), nums.end());
  int maxKind = st.size();
  if (maxKind >= n / 2)
    return n / 2;
  else
    return maxKind;
}