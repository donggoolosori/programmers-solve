#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getReverseTernary(int num) {
  string ret = "";
  while (num != 0) {
    ret += to_string(num % 3);
    num /= 3;
  }
  return ret;
}

int getDecimal(string &s) {
  int ret = 0;
  int mul = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    ret += mul * (s[i] - '0');
    mul *= 3;
  }
  return ret;
}

int solution(int n) {
  string r_ternary = getReverseTernary(n);
  int answer = getDecimal(r_ternary);
  return answer;
}