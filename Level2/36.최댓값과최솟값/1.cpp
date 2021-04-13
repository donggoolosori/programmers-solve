// 0.03ms
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    int minVal = 987654321, maxVal = -987654321;
    int start = 0;

    for (int idx = 0; idx < s.length(); idx++)
    {
        if (s[idx] == ' ')
        {
            minVal = min(minVal, stoi(s.substr(start, idx - start)));
            maxVal = max(maxVal, stoi(s.substr(start, idx - start)));
            start = idx + 1;
        }
    }
    minVal = min(minVal, stoi(s.substr(start)));
    maxVal = max(maxVal, stoi(s.substr(start)));
    return to_string(minVal) + " " + to_string(maxVal);
}