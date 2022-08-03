#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;
  vector<int> code;
  for (int i = 0; i < n; i++) {
    code.push_back(arr1[i] | arr2[i]);
  }
  for (auto c : code) {
    string binary = "";
    while (c != 0) {
      binary += c % 2 == 0 ? " " : "#";
      c /= 2;
    }
    while (binary.length() < n) {
      binary += " ";
    }
    reverse(binary.begin(), binary.end());
    answer.push_back(binary);
  }
  return answer;
}