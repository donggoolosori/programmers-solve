#include <algorithm>
#include <string>
#include <vector>
#define ll long long
using namespace std;

ll getCalc(ll mid, vector<int> &times) {
  ll ret = 0;
  for (const auto &time : times) {
    ret += mid / time;
  }
  return ret;
}

ll solution(int n, vector<int> times) {
  sort(times.begin(), times.end());
  ll low = times[0], high = times.back() * times.size();
  while (low < high) {
    ll mid = (low + high) / 2;
    if (getCalc(mid, times) >= n) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}