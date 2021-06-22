#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
  vector<int> score(3);
  stringstream ss(dartResult);

  for (int i = 0; i < 3; i++) {
    int num;
    char bonus, option;

    ss >> num;
    bonus = ss.get();
    option = ss.get();
    if (option != '*' && option != '#') ss.unget();

    score[i] = num;
    if (bonus == 'D')
      score[i] *= num;
    else if (bonus == 'T')
      score[i] *= num * num;

    if (option == '*') {
      score[i] *= 2;
      if (i > 0) score[i - 1] *= 2;
    } else if (option == '#') {
      score[i] = -score[i];
    }
  }

  return score[0] + score[1] + score[2];
}