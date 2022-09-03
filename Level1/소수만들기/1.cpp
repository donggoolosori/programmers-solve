#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int isPrime[3001];

void eratos() {
  for (int i = 2; i <= 3000; i++) isPrime[i] = true;
  for (int i = 2; i <= sqrt(3000); i++) {
    for (int j = i * i; j <= 3000; j += i) {
      isPrime[j] = false;
    }
  }
}

int solution(vector<int> nums) {
  int cnt = 0;
  int n = nums.size();
  eratos();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = nums[i] + nums[j] + nums[k];
        if (isPrime[sum]) {
          cnt++;
        }
      }
    }
  }
  return cnt;
}