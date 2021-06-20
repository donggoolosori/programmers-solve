#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Pos {
  int y, x;
};
unordered_map<int, Pos> pos;
int left_pos = 10, right_pos = 12;

char getHand(int num, const string &hand) {
  if (num == 1 || num == 4 || num == 7) {
    left_pos = num;
    return 'L';
  } else if (num == 3 || num == 6 || num == 9) {
    right_pos = num;
    return 'R';
  } else {
    int y = pos[num].y, x = pos[num].x;
    int ly = pos[left_pos].y, lx = pos[left_pos].x;
    int ry = pos[right_pos].y, rx = pos[right_pos].x;
    int l_dist = abs(y - ly) + abs(x - lx);
    int r_dist = abs(y - ry) + abs(x - rx);

    if (l_dist < r_dist) {
      left_pos = num;
      return 'L';
    } else if (r_dist < l_dist) {
      right_pos = num;
      return 'R';
    } else {
      if (hand == "right") {
        right_pos = num;
        return 'R';
      } else {
        left_pos = num;
        return 'L';
      }
    }
  }
}

string solution(vector<int> numbers, string hand) {
  string answer = "";

  for (int i = 1; i <= 12; i++) {
    int y = (i - 1) / 3;
    int x = (i - 1) % 3;
    pos[i] = {y, x};
  }
  pos[0] = {3, 1};

  for (const auto &num : numbers) {
    answer += getHand(num, hand);
  }

  return answer;
}