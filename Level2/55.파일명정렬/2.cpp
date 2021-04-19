// 1.59ms
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct FileInfo
{
    string origin, head;
    int number, index;
};

FileInfo getFileInfo(const string &s, const int idx)
{
    string head = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            // 소문자변환
            transform(head.begin(), head.end(), head.begin(), ::tolower);
            // number 추출
            string num = "";
            int j = i;
            while (j < s.length() && isdigit(s[j]))
                num += s[j++];
            // 반환
            return {s, head, stoi(num), idx};
        }
        else
            head += s[i];
    }
}

bool compare(FileInfo a, FileInfo b)
{
    if (a.head == b.head)
    {
        if (a.number == b.number)
            return a.index < b.index;
        return a.number < b.number;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<FileInfo> vec;

    int index = 0;
    for (const string &file : files)
        vec.push_back(getFileInfo(file, index++));

    sort(vec.begin(), vec.end(), compare);

    for (const auto &iter : vec)
        answer.push_back(iter.origin);

    return answer;
}