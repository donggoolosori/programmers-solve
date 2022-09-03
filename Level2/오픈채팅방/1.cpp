// 235ms
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    string command;
    string ID;
    string uid;
    map<string, string> m;

    for (string input : record)
    {
        stringstream ss(input);
        ss >> command;
        ss >> uid;
        if (command == "Enter" || command == "Change")
        {
            ss >> ID;
            m[uid] = ID;
        }
    }

    for (string input : record)
    {
        stringstream ss(input);
        ss >> command;
        ss >> uid;
        if (command == "Enter")
        {
            ID = (m.find(uid)->second);

            string temp = ID + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (command == "Leave")
        {
            ID = (m.find(uid)->second);
            string temp = ID + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    return answer;
}