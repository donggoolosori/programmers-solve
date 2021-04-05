#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    vector<string> stringNumbers;
    for (auto n : numbers)
        stringNumbers.push_back(to_string(n));
    sort(stringNumbers.begin(), stringNumbers.end(), compare);
    if (stringNumbers[0] == "0")
        return "0";
    string answer = "";
    for (auto sn : stringNumbers)
    {
        answer += sn;
    }
    return answer;
}