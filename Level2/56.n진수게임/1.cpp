// 6.78ms
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convertToN(int num, int n)
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
        {
            ret = to_string(rem) + ret;
        }
        num /= n;
    }

    return ret;
}

string solution(int n, int t, int m, int p)
{
    string prepare = "0";

    int i = 1;
    while (prepare.length() < t * m)
    {
        prepare += convertToN(i++, n);
    }

    string answer = "";
    for (int i = 0; i < prepare.length(); i++)
    {
        if (answer.length() == t)
            break;
        if (i % m == p - 1)
            answer += prepare[i];
    }

    return answer;
}