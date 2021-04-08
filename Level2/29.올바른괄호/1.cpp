// 0.55ms
#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;

    for (auto ch : s)
    {
        if (ch == '(')
            stk.push(ch);
        else
        {
            if (stk.empty())
            {
                answer = false;
                break;
            }
            else
                stk.pop();
        }
    }
    if (!stk.empty())
        answer = false;

    return answer;
}