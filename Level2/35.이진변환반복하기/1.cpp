/*
0.22ms
단순 재귀함수
*/
#include <string>
#include <vector>

using namespace std;
int zero_cnt, cnt;

// 1의 개수 세기
int countOne(const string &s)
{
    int ret = 0;
    for (const auto &ch : s)
        if (ch == '1')
            ret++;
    return ret;
}

// 이진수로 변환
string getBinary(int num)
{
    string ret = "";
    while (num != 0)
    {
        int rem = num % 2;
        num /= 2;
        ret = to_string(rem) + ret;
    }
    return ret;
}

void binaryConvert(string s)
{
    if (s == "1")
        return;

    cnt++;

    int len = s.length();  // 문자열 길이
    int one = countOne(s); // 문자열에서 1의 개수
    zero_cnt += len - one;

    string newStr = getBinary(one);
    binaryConvert(newStr);
}

vector<int> solution(string s)
{
    binaryConvert(s);
    return {cnt, zero_cnt};
}