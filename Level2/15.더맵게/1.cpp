// 206.92ms
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    // 굳이 다시 반복문을 돌 필요없이 위처럼 선언과 동시에 assign 할 수 있음.
    // for(const auto &s:scoville) pq.push(s);

    while (pq.top() < K && pq.size() >= 2)
    {
        answer++;

        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        int newS = s1 + s2 * 2;
        pq.push(newS);
    }
    if (pq.top() < K)
        return -1;
    return answer;
}