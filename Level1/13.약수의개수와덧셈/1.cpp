#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool odd[1001];

int solution(int left, int right) {
  for (int i = 1; i <= sqrt(1000); i++) {
    odd[i * i] = true;
  }
  int sum = 0;
  for (int i = left; i <= right; i++) {
    if (odd[i]) {
      sum -= i;
    } else {
      sum += i;
    }
  }
  return sum;
}