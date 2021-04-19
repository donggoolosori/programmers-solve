#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MusicInfo
{
    int playMinute;
    string title, melody;
};

// #이 붙어있는 음표들을 다른 알파벳으로 변환
string convertSharp(const string &s)
{
    string ret = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length() && s[i + 1] == '#')
        {
            ret += (s[i] + 7);
            i++;
        }
        else
            ret += s[i];
    }
    return ret;
}

// musicinfos 정보를 정제해서 반환하는 함수
vector<MusicInfo> getMusicInfo(const vector<string> &musicinfos)
{
    vector<MusicInfo> ret;

    for (const auto &info : musicinfos)
    {
        vector<string> vec;
        string temp = "";
        for (const char &ch : info)
        {
            if (ch == ',')
            {
                vec.push_back(temp);
                temp = "";
            }
            else
                temp += ch;
        }
        vec.push_back(temp);

        int sH = stoi(vec[0].substr(0, 2));
        int sM = stoi(vec[0].substr(3, 2));
        int eH = stoi(vec[1].substr(0, 2));
        int eM = stoi(vec[1].substr(3, 2));
        int playMinute = (eH - sH) * 60 + (eM - sM);
        string title = vec[2], melody = convertSharp(vec[3]);
        ret.push_back({playMinute, title, melody});
    }

    return ret;
}

// 플레이시간의 내림차순으로 정렬
bool compare(MusicInfo a, MusicInfo b)
{
    return a.playMinute > b.playMinute;
}

string solution(string m, vector<string> musicinfos)
{
    m = convertSharp(m);
    vector<MusicInfo> newInfos = getMusicInfo(musicinfos); // musicinfos 정제하기
    vector<MusicInfo> candidate;                           // 답 후보들 저장

    for (const auto &info : newInfos)
    {
        int mLen = info.melody.length();
        int playMinute = info.playMinute;
        int quot = playMinute / mLen, rem = playMinute % mLen;

        string newS = "";
        for (int i = 0; i < quot; i++)
            newS += info.melody;
        newS += info.melody.substr(0, rem);

        if (newS.find(m) != string::npos)
            candidate.push_back(info);
    }

    if (candidate.empty())
        return "(None)";
    sort(candidate.begin(), candidate.end(), compare);
    return candidate[0].title;
}