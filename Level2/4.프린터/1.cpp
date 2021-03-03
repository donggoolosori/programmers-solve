// 0.1ms
// 우선순위 큐, pair 자료형 사용
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int index = 0;
    for (const auto &p : priorities)
    {
        q.push({p, index++});
        pq.push(p);
    }

    int order = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        cout << cur.first << ' ' << cur.second << '\n';
        if (pq.top() <= cur.first)
        {
            if (cur.second == location)
            {
                return order;
            }
            q.pop();
            pq.pop();
            order++;
        }
        else
        {
            q.push(cur);
            q.pop();
        }
    }
}