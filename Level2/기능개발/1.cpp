#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;
    // 각 작업마다 완료에 필요한 day를 큐에 push
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int day = remain % speeds[i] == 0 ? remain / speeds[i] : remain / speeds[i] + 1;
        q.push(day);
    }

    int cnt = 0, max = q.front();
    while (!q.empty())
    {
        if (q.front() <= max)
        {
            cnt++;
        }
        else
        {
            answer.push_back(cnt);
            max = q.front();
            cnt = 1;
        }
        q.pop();
    }
    answer.push_back(cnt);
    return answer;
}