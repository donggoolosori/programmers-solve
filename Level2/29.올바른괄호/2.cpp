// 0.54ms
#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;

    for (const char &ch : s)
    {
        if (ch == '(')
            stk.push(ch);
        else
        {
            if (stk.empty())
                return false;
            else
                stk.pop();
        }
    }
    if (!stk.empty())
        return false;

    return true;
}