// 0.02ms
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    bool check = true; //false면 소문자로, true면 대문자로
    for (auto &ch : s)
    {
        if (ch == ' ')
        {
            check = true;
            continue;
        }
        // 첫글자일 경우
        if (check)
        {
            if (ch >= 'a' && ch <= 'z')
                ch -= 32;
            check = false;
        }
        // 첫글자가 아닌 문자면서 대문자일 경우
        else if (!check && ch >= 'A' && ch <= 'Z')
            ch += 32;
    }

    return s;
}