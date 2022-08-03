#include <string>
#include <vector>
#define ll long long

using namespace std;

ll solution(int a, int b) {
  if (a > b) swap(a, b);
  ll answer = 0;
  ll len = b - a + 1;
  answer = (a + b) * (len / 2);
  if (len % 2 == 1) answer += (a + b) / 2;

  return answer;
}