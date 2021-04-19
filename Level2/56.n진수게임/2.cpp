// 6.84ms
#include <string>
#include <vector>

using namespace std;

string convertN(int n, int num)
{
    string ret = "";

    int rem;
    while (num > 0)
    {
        rem = num % n;
        if (rem >= 10)
        {
            char ch = 'A' + (rem - 10);
            ret = ch + ret;
        }
        else
            ret = to_string(rem) + ret;
        num /= n;
    }

    return ret;
}

string getOutput(int len, int n)
{
    string ret = "0";
    int val = 1;
    while (ret.length() <= len)
    {
        string curr = convertN(n, val++);
        ret += curr;
    }
    return ret;
}

string solution(int n, int t, int m, int p)
{
    string prepare = getOutput(t * m, n);

    string answer = "";
    int idx = p - 1;
    for (int i = 0; i < t; i++)
    {
        answer += prepare[idx];
        idx += m;
    }
    return answer;
}