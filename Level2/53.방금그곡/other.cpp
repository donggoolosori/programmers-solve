// 0.31ms
#include <string>
#include <vector>

using namespace std;

string convertSharp(string notes)
{
    string ret = "";
    const int diff = 'A' - 'a';
    for (int i = 0; i < notes.size(); i++)
    {
        if (i < notes.size() - 1 && notes.at(i + 1) == '#')
        {
            ret.push_back((char)(notes.at(i) - diff));
            i++;
        }
        else
        {
            ret.push_back(notes.at(i));
        }
    }
    return ret;
}

string getNotesToFind(string info, int countToFind, string &title)
{
    string ret = "";

    const int maxTime = 24 * 60;
    int begin = stoi(info.substr(0, 2)) * 60 + stoi(info.substr(3, 2));
    int end = stoi(info.substr(6, 2)) * 60 + stoi(info.substr(9, 2));
    int runLength = begin >= maxTime ? 0 : min(maxTime, end) - begin;
    if (countToFind > runLength)
        return ret;

    title = info.substr(12, info.rfind(',') - 12);
    int notePtr = 13 + title.size();
    int noteLength = info.size() - notePtr;
    string notes = convertSharp(info.substr(notePtr, noteLength));
    noteLength = notes.size();
    for (int r = 0; r < runLength / noteLength; r++)
    {
        ret = ret.append(notes);
    }
    ret = ret.append(notes, 0, runLength % noteLength);
    return ret;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";

    int length = 0;
    for (auto it = musicinfos.begin(); it != musicinfos.end(); it++)
    {
        string title;
        string fnotes = convertSharp(m);
        string notes = getNotesToFind(*it, fnotes.size(), title);
        if (notes.find(fnotes) != string::npos && notes.size() > length)
        {
            answer = title;
            length = notes.size();
        }
    }

    return answer;
}