// 9.67ms
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;
    unordered_map<int, int> um;

    string temp = "";
    for (auto ch : s)
    {
        if (ch - '0' >= 0 && ch - '0' <= 9)
        {
            temp = temp + ch;
        }
        else
        {
            if (temp.length())
            {
                um[stoi(temp)]++;
                temp = "";
            }
        }
    }

    vector<pair<int, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), compare);

    for (auto el : v)
    {
        // cout<<el.second<<'\n';
        answer.push_back(el.first);
    }
    return answer;
}