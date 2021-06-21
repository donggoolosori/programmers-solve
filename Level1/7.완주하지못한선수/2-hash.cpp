#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  unordered_map<string, int> ht;

  for (const auto &c : completion) {
    ht[c]++;
  }
  for (const auto &p : participant) {
    if (ht.find(p) == ht.end()) {
      return p;
    } else {
      ht[p]--;
      if (ht[p] < 0) {
        return p;
      }
    }
  }
}