/*
0.02ms
완전탐색 사용
next_permutation을 사용하기 전에 정렬 필수. 다음 순열만을 반환하기 때문에 모든 순열을 얻으려면 정렬을 해야함
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

vector<ll> num;
vector<char> op_pmt, op_loc;

void setNumAndOp(const string &expression)
{
    string temp = "";

    for (const auto &ch : expression)
    {
        if (!isdigit(ch))
        {
            num.push_back(stoll(temp));
            op_loc.push_back(ch);
            if (find(op_pmt.begin(), op_pmt.end(), ch) == op_pmt.end())
                op_pmt.push_back(ch);
            temp = "";
        }
        else
            temp += ch;
    }
    num.push_back(stoll(temp));
    sort(op_pmt.begin(), op_pmt.end());
}

ll getCalculation(ll a, ll b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    return a * b;
}

ll getMax()
{
    ll ret = 0;
    do
    {
        vector<ll> temp_num = num;
        vector<char> temp_loc = op_loc;

        for (const auto &op : op_pmt)
        {
            for (int i = 0; i < temp_loc.size(); i++)
            {
                if (op == temp_loc[i])
                {
                    temp_num[i] = getCalculation(temp_num[i], temp_num[i + 1], op);
                    temp_num.erase(temp_num.begin() + i + 1);
                    temp_loc.erase(temp_loc.begin() + i);
                    i--;
                }
            }
        }

        ret = max(ret, abs(temp_num[0]));
    } while (next_permutation(op_pmt.begin(), op_pmt.end()));

    return ret;
}

ll solution(string expression)
{
    setNumAndOp(expression);

    return getMax();
}