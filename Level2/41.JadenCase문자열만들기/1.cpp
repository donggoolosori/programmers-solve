// 0.01ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    bool isFirst = true;
    for (auto &ch : s)
    {
        if (ch == ' ')
        {
            isFirst = true;
            continue;
        }
        // 첫글자일 경우
        if (isFirst)
        {
            // 소문자이면 대문자로 교체
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch - 32;
            }
            isFirst = false;
            // 첫글자 아닐 경우
        }
        else
        {
            // 대문자면 소문자로 교체
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 32;
            }
        }
    }
    return s;
}