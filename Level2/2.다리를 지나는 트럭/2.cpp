/*
1.65ms
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> q;

    int curr = 0, time = 0, index = 0;

    while (true)
    {
        if (index == truck_weights.size())
        {
            time += bridge_length;
            break;
        }

        if (q.size() == bridge_length)
        {
            curr -= q.front();
            q.pop();
        }

        int next = truck_weights[index];
        if (curr + next <= weight)
        {
            curr += next;
            q.push(next);
            index++;
        }
        else
        {
            q.push(0);
        }

        time++;
    }

    return time;
}