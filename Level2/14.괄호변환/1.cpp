// 0.13ms
#include <string>
#include <vector>
#include <stack>

using namespace std;

int getDivideIdx(string s)
{
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            cnt1++;
        else
            cnt2++;

        if (cnt1 != 0 && cnt1 == cnt2)
            return i;
    }
}

string getReverse(string u)
{
    for (auto &c : u)
    {
        if (c == '(')
            c = ')';
        else
            c = '(';
    }
    return u;
}

bool isRight(string u)
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

string recur(string s)
{
    if (s == "")
        return "";

    int idx = getDivideIdx(s);
    string u = s.substr(0, idx + 1);
    string v = s.substr(idx + 1);

    if (isRight(u))
    {
        v = recur(v);
        return u + v;
    }
    else
    {
        string ret = "(";
        ret += recur(v) + ')';
        u.pop_back();
        ret += getReverse(u.substr(1));
        return ret;
    }
}

string solution(string p)
{

    return recur(p);
}