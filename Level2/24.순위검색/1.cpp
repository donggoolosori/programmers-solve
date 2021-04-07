/*
정확성은 모두 맞았지만
효율성 검사에서 모두 시간초과
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Apl
{
    string code;
    int score;
};

vector<Apl> organizeInfo(const vector<string> &info)
{
    vector<Apl> ret;

    for (const auto &s : info)
    {
        Apl newApl;
        // 코드 추출
        int idx = 0;
        string code = "";
        for (int i = 0; i < s.length(); i++)
        {
            // 공백 만남
            if (s[i] == ' ')
            {
                code += s[idx];
                idx = i + 1;
            }
        }
        newApl.code = code;
        // 점수 추출
        newApl.score = stoi(s.substr(idx));
        ret.push_back(newApl);
    }
    return ret;
}

vector<Apl> organizeQuery(const vector<string> &query)
{
    vector<Apl> ret;

    for (const auto &s : query)
    {
        Apl newApl;
        // 코드 추출
        int idx = 0;
        string code = "";
        for (int i = 0; i < s.length(); i++)
        {
            // 공백 만남
            if (s[i] == ' ')
            {
                if (s[i + 1] >= '0' && s[i + 1] <= '9')
                {
                    code += s[idx];
                    idx = i + 1;
                    break;
                }
                code += s[idx];
                i += 5;
                idx = i;
            }
        }
        newApl.code = code;
        // 점수 추출
        newApl.score = stoi(s.substr(idx));
        ret.push_back(newApl);
    }
    return ret;
}

bool compare(Apl a, Apl b)
{
    return a.score > b.score;
}

bool isMatched(string icode, string qcode)
{
    for (int i = 0; i < 4; i++)
    {
        if (qcode[i] == '-')
            continue;
        if (icode[i] != qcode[i])
            return false;
    }
    return true;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    vector<Apl> orgInfo = organizeInfo(info);
    sort(orgInfo.begin(), orgInfo.end(), compare);
    vector<Apl> orgQuery = organizeQuery(query);

    for (const auto &q : orgQuery)
    {
        int cnt = 0;
        for (const auto &i : orgInfo)
        {
            if (q.score > i.score)
                break;
            if (isMatched(i.code, q.code))
            {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}