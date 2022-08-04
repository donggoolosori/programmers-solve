// 0.38ms
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s)
{
    int minLen = 1000;
    int len = s.length();

    if (len == 1)
        return 1;

    // unit : 압축단위, init : 자르는 문자들의 첫 인덱스
    for (int unit = 1; unit <= len / 2; unit++)
    {

        string cur = s.substr(0, unit);
        int cnt = 1, zip = len;

        for (int init = unit; init < len; init += unit)
        {
            string temp;
            if (unit == 1)
                temp = s[init];
            else
                temp = s.substr(init, unit);

            if (temp == cur)
            {
                cnt++;
            }
            else
            {
                cur = temp;
                if (cnt == 1)
                    continue;
                zip -= (cnt - 1) * unit;
                zip += to_string(cnt).length();
                cnt = 1;
            }
        }
        if (cnt != 1)
        {
            zip -= (cnt - 1) * unit;
            zip += to_string(cnt).length();
        }
        // cout<<"단위 : "<<unit<<", 길이 : "<<zip<<", cnt: "<<cnt<<'\n';
        minLen = min(minLen, zip);
    }

    return minLen;
}