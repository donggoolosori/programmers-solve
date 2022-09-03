// 107.82ms
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Action
{
    string action, uid;
};
unordered_map<string, string> users;

vector<string> getAction(const string &s)
{
    string temp = "";
    vector<string> ret;
    for (const auto &ch : s)
    {
        if (ch == ' ')
        {
            ret.push_back(temp);
            temp = "";
        }
        else
            temp += ch;
    }
    ret.push_back(temp);

    return ret;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<Action> actions;

    for (const auto &r : record)
    {
        vector<string> vec = getAction(r);
        actions.push_back({vec[0], vec[1]});

        if (vec[0] != "Leave")
            users[vec[1]] = vec[2];
    }

    for (const auto &a : actions)
    {
        string curr = users[a.uid] + "님이 ";
        if (a.action == "Change")
            continue;
        if (a.action == "Enter")
            curr += "들어왔습니다.";
        else
            curr += "나갔습니다.";
        answer.push_back(curr);
    }

    return answer;
}