#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  set<int> st;
  for (int i = 0; i < numbers.size(); i++) {
    for (int j = i + 1; j < numbers.size(); j++) {
      st.insert(numbers[i] + numbers[j]);
    }
  }

  vector<int> answer(st.begin(), st.end());

  return answer;
}