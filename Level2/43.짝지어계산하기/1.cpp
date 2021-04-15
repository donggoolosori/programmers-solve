// 6.03ms
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stk;
    if (s.length() % 2 != 0)
        return 0;
    for (auto ch : s)
    {
        if (!stk.empty() && stk.top() == ch)
            stk.pop();
        else
            stk.push(ch);
    }
    if (stk.empty())
        return 1;
    else
        return 0;
}