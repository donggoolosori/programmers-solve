// 218.3ms
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.size() >= 2)
    {
        answer++;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int newK = first + 2 * second;
        pq.push(newK);

        if (pq.top() >= K)
            break;
    }
    if (pq.top() < K)
        return -1;

    return answer;
}