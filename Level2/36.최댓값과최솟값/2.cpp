// 0.02ms
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    int minNum = 987654321, maxNum = -987654321;

    string temp = "";
    int num;

    for (const auto &ch : s)
    {
        if (ch == ' ')
        {
            num = stoi(temp);
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
            temp = "";
        }
        else
            temp += ch;
    }
    num = stoi(temp);
    minNum = min(minNum, num);
    maxNum = max(maxNum, num);

    return to_string(minNum) + " " + to_string(maxNum);
}