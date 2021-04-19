// 1.59ms
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node
{
    string name;
    string header;
    int num, index;
};

// 정렬기준 header -> number -> index
bool compare(Node a, Node b)
{
    if (a.header == b.header)
    {
        if (a.num == b.num)
            return a.index < b.index;
        return a.num < b.num;
    }
    return a.header < b.header;
}

// files의 text들을 파일명, 헤더, 숫자, 인덱스번호로 나눠서 반환
vector<Node> divideTexts(vector<string> &files)
{
    vector<Node> ret;
    int index = 0, ns, ne;

    for (auto file : files)
    {
        string header = "", num = "";

        for (int i = 0; i < file.length(); i++)
        {
            if (isdigit(file[i]))
            {
                ns = i;
                break;
            }
            header += tolower(file[i]);
        }

        for (int i = ns; i < ns + 5; i++)
        {
            if (!isdigit(file[i]))
                break;
            num += file[i];
        }

        ret.push_back({file, header, stoi(num), index++});
    }

    return ret;
}

vector<string> solution(vector<string> files)
{

    vector<Node> divided = divideTexts(files);
    sort(divided.begin(), divided.end(), compare);

    vector<string> answer;
    for (const auto &iter : divided)
    {
        answer.push_back(iter.name);
    }
    return answer;
}