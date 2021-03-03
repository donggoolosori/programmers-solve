#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0, curW = 0, index = 0;
    queue<int> q;

    while (true)
    {
        if (index == truck_weights.size())
        {
            time += bridge_length;
            break;
        }

        time++;

        if (q.size() == bridge_length)
        {
            curW -= q.front();
            q.pop();
        }

        int wait = truck_weights[index];

        if (curW + wait <= weight)
        {
            curW += wait;
            q.push(wait);
            index++;
        }
        else
        {
            q.push(0);
        }
    }

    return time;
}