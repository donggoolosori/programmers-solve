/*
속도 : 0.02ms
1. 우선순위 큐 사용
2. 구조체 만듬
3. 코드1 보다 5배 빠름
4. 1과 다르게 prt와 idx 변수를 미리 할당해서 속도가 빨라진듯함
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int prt, idx;
};

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<Node> q;

    // 우선순위 큐 초기화
    int index = 0;
    for (const auto &p : priorities)
    {
        q.push({p, index++});
        pq.push(p);
    }

    int cnt = 1;

    while (!q.empty())
    {
        int prt = q.front().prt;
        int idx = q.front().idx;

        if (prt >= pq.top())
        {
            if (idx == location)
            {
                answer = cnt;
                break;
            }
            pq.pop();
            cnt++;
        }
        else
        {
            q.push({prt, idx});
        }
        q.pop();
    }

    return answer;
}