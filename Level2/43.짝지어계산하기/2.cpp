// 4.84ms
// 1보다 1ms 이상 빠름 -> 반복문에서 참조형을 사용했기 때문
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stk;

    for (const char &ch : s)
    {
        if (!stk.empty() && ch == stk.top())
            stk.pop();
        else
            stk.push(ch);
    }
    if (!stk.empty())
        return 0;
    return 1;
}