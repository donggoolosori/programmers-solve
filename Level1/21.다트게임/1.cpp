#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
  vector<int> score(3);
  int len = dartResult.length();
  string s_num = "";
  int idx = 0;
  for (int i = 0; i < len; i++) {
    char curr = dartResult[i];
    if (isdigit(curr)) {
      s_num += curr;
    } else {
      int num = stoi(s_num);
      s_num = "";
      score[idx] = num;

      if (curr == 'D')
        score[idx] *= num;
      else if (curr == 'T')
        score[idx] *= num * num;

      if (i + 1 < len && !isdigit(dartResult[i + 1])) {
        if (dartResult[i + 1] == '*') {
          score[idx] *= 2;
          if (idx > 0) score[idx - 1] *= 2;
        } else {
          score[idx] = -score[idx];
        }
        i++;
      }

      idx++;
    }
  }

  int answer = score[0] + score[1] + score[2];

  return answer;
}