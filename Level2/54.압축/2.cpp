// 0.26ms
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> dict;

vector<int> solution(string msg)
{
    vector<int> answer;
    int len = msg.length();

    // 사전 초기화
    for (int i = 0; i < 26; i++)
    {
        string temp = "";
        temp += ('A' + i);
        dict[temp] = i + 1;
    }

    int val = 27;
    for (int i = 0; i < len; i++)
    {
        string curr = msg.substr(i, 1);

        int j = i + 1, cnt = 0;
        while (dict.count(curr) == 1)
        {
            cnt++;
            curr += msg[j++];
        }
        i += cnt - 1;
        dict[curr] = val++;
        curr.pop_back();
        answer.push_back(dict[curr]);
    }

    return answer;
}