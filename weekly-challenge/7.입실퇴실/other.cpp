#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
  vector<int> answer;

  int n = enter.size();

  set<int> meetingRoom;
  map<pair<int, int>, bool> areMet;

  int enterIdx = 0, leaveIdx = 0;

  while (leaveIdx < n) {
    while (meetingRoom.find(leave[leaveIdx]) == meetingRoom.end()) {
      int enterPerson = enter[enterIdx++];
      meetingRoom.insert(enterPerson);

      for (int person : meetingRoom) {
        areMet[{person, enterPerson}] = true;
        areMet[{enterPerson, person}] = true;
      }
    }

    while (leaveIdx < n &&
           meetingRoom.find(leave[leaveIdx]) != meetingRoom.end()) {
      meetingRoom.erase(leave[leaveIdx++]);
    }
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;

    for (int j = 1; j <= n; j++) {
      if (i == j) continue;

      if (areMet[{i, j}]) cnt++;
    }

    answer.push_back(cnt);
  }

  return answer;
}