#include <string>
#include <vector>

using namespace std;

string weekday[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
  int day = 0;
  for (int i = 1; i < a; i++) {
    day += days[i];
  }
  day += b;
  return weekday[day % 7];
}