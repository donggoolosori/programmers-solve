/*
29.9ms
*/
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int len = prices.size();
    vector<int> answer(len);
    stack<pair<int, int>> s;

    for (int i = 0; i < len; i++)
    {
        if (s.empty() || s.top().first <= prices[i])
            s.push({prices[i], i});
        else
        {
            while (!s.empty() && s.top().first > prices[i])
            {
                int in_time = s.top().second;
                answer[in_time] = i - in_time;
                s.pop();
            }
            s.push({prices[i], i});
        }
    }
    while (!s.empty())
    {
        int in_time = s.top().second;
        answer[in_time] = len - in_time - 1;
        s.pop();
    }
    return answer;
}