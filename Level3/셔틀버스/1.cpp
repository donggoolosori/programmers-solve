#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getIntTimeTable(const vector<string> &timetable) {
  vector<int> ret;

  for (const auto &time : timetable) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    ret.push_back(h * 60 + m);
  }

  return ret;
}

string intToStr(int time) {
  string ret = "";

  int h = time / 60;
  int m = time % 60;

  if (h < 10) ret += "0";
  ret += to_string(h);
  ret += ":";

  if (m < 10) ret += "0";
  ret += to_string(m);

  return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> newtable = getIntTimeTable(timetable);
  sort(newtable.begin(), newtable.end());

  // 가장 마지막 셔틀에 자리가 남는 경우, 마지막 버스의 도착 시간
  // 남지 않는 경우, 마지막에 탑승한 승객 - 1
  int bus_time = 540;
  int crew_idx = 0;
  for (int i = 1; i <= n; i++, bus_time += t) {
    int cnt = 0;

    for (int j = crew_idx; j < newtable.size(); j++) {
      if (newtable[j] > bus_time) break;

      cnt++;
      crew_idx++;
      if (cnt == m) break;
    }

    if (i == n) {
      if (cnt == m) {
        return intToStr(newtable[crew_idx - 1] - 1);
      } else {
        return intToStr(bus_time);
      }
    }
  }

  return 0;
}