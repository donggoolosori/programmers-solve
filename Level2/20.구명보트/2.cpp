// 1.75ms
// deque 사용
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());

    deque<int> dq(people.begin(), people.end());

    while (!dq.empty())
    {
        answer++;
        if (dq.size() >= 2 && dq.front() + dq.back() <= limit)
        {
            dq.pop_front();
            dq.pop_back();
        }
        else
            dq.pop_front();
    }
    return answer;
}