#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void step1(string &id) {
  transform(id.begin(), id.end(), id.begin(), ::tolower);
}

void step2(string &id) {
  string temp = "";
  for (auto &ch : id) {
    if (isdigit(ch) || (ch >= 'a' && ch <= 'z') || ch == '-' || ch == '_' ||
        ch == '.')
      temp += ch;
  }
  id = temp;
}

void step3(string &id) {
  string temp = "";
  for (int i = 0; i < id.length(); i++) {
    if (i < id.length() - 1 && id[i] == '.' && id[i + 1] == '.') continue;
    temp += id[i];
  }
  id = temp;
}

void step4(string &id) {
  if (id[0] == '.') id = id.substr(1);
  if (id.back() == '.') id.pop_back();
}

void step5(string &id) {
  if (id.empty()) id = "a";
}

void step6(string &id) {
  if (id.length() >= 16) {
    id = id.substr(0, 15);
    if (id.back() == '.') id.pop_back();
  }
}

void step7(string &id) {
  while (id.length() < 3) {
    id += id.back();
  }
}

string solution(string new_id) {
  step1(new_id);
  step2(new_id);
  step3(new_id);
  step4(new_id);
  step5(new_id);
  step6(new_id);
  step7(new_id);

  return new_id;
}