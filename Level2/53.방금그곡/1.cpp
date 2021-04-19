// 4.42ms
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node
{
    int time, index;
    string title;
};

// C#,D#,F#,G#,A# 을 다른문자로변환
string delHash(string s)
{
    string temp = "";
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (i + 1 < len && s[i] != '#' && s[i + 1] == '#')
        {
            if (s[i] == 'C')
                temp = temp + 'c';
            else if (s[i] == 'D')
                temp = temp + 'd';
            else if (s[i] == 'F')
                temp = temp + 'f';
            else if (s[i] == 'G')
                temp = temp + 'g';
            else if (s[i] == 'A')
                temp = temp + 'a';
            i++;
        }
        else
            temp = temp + s[i];
    }
    cout << temp << '\n';
    return temp;
}

// string인 음악정보를 나눈 vector 반환
vector<string> getInfoVector(string info)
{
    vector<string> res;
    int start = 0;
    for (int i = 0; i < info.length(); i++)
    {
        if (info[i] == ',')
        {
            res.push_back(info.substr(start, i - start));
            start = i + 1;
        }
    }
    res.push_back(info.substr(start));

    res[3] = delHash(res[3]);

    return res;
}

// 음악 재생시간 반환
int getPlayTime(string start, string end)
{
    int sH = stoi(start.substr(0, 2));
    int eH = stoi(end.substr(0, 2));
    int sM = stoi(start.substr(3));
    int eM = stoi(end.substr(3));
    // if(eH==0) eH=24;
    int ret = (eH - sH) * 60 + (eM - sM);
    return ret;
}

// 실제 재생된 음악의 악보 반환
string getActual(int time, string s)
{
    string ret = "";
    int len = s.length();
    if (time < len)
        return s.substr(0, time);
    for (int i = 0; i < (time / len); i++)
    {
        ret += s;
    }
    ret += s.substr(0, time % len);
    return ret;
}

// 재생된 음악이 기억과 일치하면 true 반환
bool check(string m, string actual)
{
    int len = m.length();
    for (int i = 0; i < actual.length(); i++)
    {
        if (actual[i] == m[0])
        {
            if (actual.substr(i, len) == m)
                return true;
        }
    }
    return false;
}

bool compare(Node a, Node b)
{
    if (a.time == b.time)
        return a.index < b.index;
    return a.time > b.time;
}

string solution(string m, vector<string> musicinfos)
{
    vector<Node> cand;
    m = delHash(m);
    int index = 0;
    for (auto info : musicinfos)
    {
        // 음악 정보 벡터로 바꾸기
        vector<string> infoVec = getInfoVector(info);
        // 재생시간 구하기
        int playTime = getPlayTime(infoVec[0], infoVec[1]);
        // 재생시간 기반으로 실제 재생악보 구하기
        string actual = getActual(playTime, infoVec[3]);
        // 기억한 악보가 새로운스트링안에 포함되면 cand에 재생시간과 제목 push
        if (check(m, actual))
            cand.push_back({playTime, index++, infoVec[2]});
    }
    // cand가 여러개면 재생시간으로 정렬
    if (cand.size() > 1)
        sort(cand.begin(), cand.end(), compare);
    // cand의 첫번째 요소의 제목 출력
    if (cand.empty())
        return "(None)";
    return cand[0].title;
}