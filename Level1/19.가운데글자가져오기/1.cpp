#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  int l = s.length();  //문자열의 길이

  // 길이가 짝수
  if (l % 2 == 0) {
    answer = s.substr(l / 2 - 1, 2);
  }
  // 길이가 홀수
  else {
    answer = s[l / 2];
  }
  return answer;
}