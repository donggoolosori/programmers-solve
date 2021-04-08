// 0.03ms
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 정수 n을 이진수로 변환
string getBinary(int n)
{
    string ret = "";
    while (n > 0)
    {
        int remain = n % 2;
        n /= 2;
        ret = to_string(remain) + ret;
    }
    return ret;
}

// 이진수에서 1의 개수를 세기
int countOne(string &s)
{
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            ret++;
    }
    return ret;
}

int solution(int n)
{
    int answer = 0;
    string start = getBinary(n);
    int one = countOne(start);

    for (int i = n + 1;; i++)
    {
        string binary = getBinary(i);
        if (one == countOne(binary))
        {
            answer = i;
            break;
        }
    }

    return answer;
}