// 163.01ms
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
    int vectorLength = n * (n + 1) / 2;
    vector<int> answer(vectorLength);

    int num = 1;
    int index = 0;
    int floor = 1;
    int dir = 0;
    int next;
    while (num <= vectorLength)
    {
        answer[index] = num++;
        // 아래로 내려갈때
        if (dir == 0)
        {
            next = index + floor;
            if (next >= vectorLength || answer[next] != 0)
            {
                dir = 1;
                index += 1;
            }
            else
            {
                index += floor;
                floor++;
            }
        }
        // 오른쪽으로 갈때
        else if (dir == 1)
        {
            next = index + 1;
            if (next >= vectorLength || answer[next] != 0)
            {
                dir = 2;
                index -= floor;
                floor--;
            }
            else
            {
                index++;
            }
        }
        // 위로 갈때
        else
        {
            next = index - floor;
            // 막힌경우
            if (next < 0 || answer[next] != 0)
            {
                dir = 0;
                index += floor;
                floor++;
            }
            else
            {
                index -= floor;
                floor--;
            }
        }
    }

    return answer;
}