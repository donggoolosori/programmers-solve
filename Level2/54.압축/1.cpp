// 0.27ms
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> dict;

void init()
{
    for (int i = 0; i < 26; i++)
    {
        string temp = "";
        temp += ('A' + i);
        dict.insert({temp, i + 1});
    }
}

vector<int> solution(string msg)
{
    vector<int> answer;
    init();

    int index = 27;
    for (int i = 0; i < msg.length(); i++)
    {
        string text = "";
        text = text + msg[i];
        int j = i, cnt = 0;

        while (dict[text] != 0)
        {
            cnt++;
            j++;
            text = text + msg[j];
        }

        i += cnt - 1;
        dict[text] = index++;
        text.pop_back();
        answer.push_back(dict[text]);
    }
    return answer;
}