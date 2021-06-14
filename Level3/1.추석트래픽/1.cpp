#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, bool>> times;

bool compare(pair<int, bool> a, pair<int, bool> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int getEndMs(string time) {
  int h = stoi(time.substr(11, 2));
  int m = stoi(time.substr(14, 2));
  int s = stoi(time.substr(17, 2));
  int ms = stoi(time.substr(20, 3));

  ms += 3600000 * h;
  ms += 60000 * m;
  ms += s * 1000;

  return ms;
}

int solution(vector<string> lines) {
  int answer = 0;

  for (const auto &line : lines) {
    int end = getEndMs(line);

    string temp = line.substr(24);
    temp.pop_back();
    int runtime = stod(temp) * 1000;

    int start = end - runtime + 1;

    times.push_back({start, true});
    times.push_back({end + 999, false});
  }

  sort(times.begin(), times.end(), compare);

  int traffic = 0;
  for (const auto &time : times) {
    if (time.second == true) {
      traffic++;
    } else {
      traffic--;
    }

    answer = max(answer, traffic);
  }

  return answer;
}