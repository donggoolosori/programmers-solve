#include <algorithm>
#include <string>
#include <vector>
#define ll long long

using namespace std;

ll solution(int n, vector<int> times) {
  sort(times.begin(), times.end());
  ll low = times[0], high = (ll)times.back() * n;

  while (low < high) {
    ll mid = (low + high) / 2;

    // mid시간 동안 심사관들이 심사할 수 있는 사람의 수를 찾는다
    ll cnt = 0;
    for (const auto &time : times) {
      cnt += mid / time;
    }
    if (cnt >= n) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}