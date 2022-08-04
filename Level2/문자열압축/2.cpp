// 0.37ms

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int len = s.length();
    int answer = len;

    for (int unit = 1; unit <= len / 2; unit++)
    {
        string std = s.substr(0, unit);
        int temp = len;
        int cnt = 1;

        for (int idx = unit; idx < len; idx += unit)
        {
            string curr = s.substr(idx, unit);

            if (std == curr)
            {
                cnt++;
            }
            else
            {
                std = curr;

                if (cnt == 1)
                    continue;
                temp -= (cnt - 1) * unit;
                temp += to_string(cnt).length();

                cnt = 1;
            }
        }
        if (cnt != 1)
        {
            temp -= (cnt - 1) * unit;
            temp += to_string(cnt).length();
        }

        answer = min(answer, temp);
    }

    return answer;
}