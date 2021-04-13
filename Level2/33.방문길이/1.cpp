// 0.01ms
// 3차원 배열 사용
#include <string>
using namespace std;

int visit[11][11][2];

int solution(string dirs)
{
    int answer = 0;
    int y = 5, x = 5;

    for (const auto &ch : dirs)
    {
        if (ch == 'U')
        {
            if (y + 1 > 10)
                continue;
            if (!visit[y][x][0])
                answer++;
            visit[y][x][0] = true;
            y += 1;
        }
        else if (ch == 'D')
        {
            if (y - 1 < 0)
                continue;
            if (!visit[y - 1][x][0])
                answer++;
            visit[y - 1][x][0] = true;
            y -= 1;
        }
        else if (ch == 'R')
        {
            if (x + 1 > 10)
                continue;
            if (!visit[y][x][1])
                answer++;
            visit[y][x][1] = true;
            x += 1;
        }
        else if (ch == 'L')
        {
            if (x - 1 < 0)
                continue;
            if (!visit[y][x - 1][1])
                answer++;
            visit[y][x - 1][1] = true;
            x -= 1;
        }
    }
    return answer;
}