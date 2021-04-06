// 0.1ms
#include <string>
#include <vector>
#include <stack>

using namespace std;

string getReverse(string u)
{

    for (auto &ch : u)
    {
        if (ch == '(')
            ch = ')';
        else
            ch = '(';
    }
    return u;
}

bool isRight(const string &u)
{
    stack<char> stk;
    for (const auto &c : u)
    {
        if (c == '(')
            stk.push(c);
        else
        {
            if (!stk.empty())
                stk.pop();
        }
    }
    if (!stk.empty())
        return false;
    return true;
}

string getRight(const string &p)
{
    if (p == "")
        return "";
    // u,v 분리
    string u = "", v = "";
    int l = 0, r = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
            l++;
        else
            r++;

        if (l == r)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    v = getRight(v);
    if (isRight(u))
    {
        return u + v;
    }
    else
    {
        u.pop_back();
        u = u.substr(1);
        return "(" + v + ")" + getReverse(u);
    }
}

string solution(string p)
{

    return getRight(p);
}