// 0.33ms
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

bool visit[100][100];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
struct Pos
{
    int y, x, dist;
};

int findMinPath(const vector<vector<int>> &maps)
{
    int r = maps.size(), c = maps[0].size();
    queue<Pos> q;

    q.push({0, 0, 1});
    visit[0][0] = true;

    while (!q.empty())
    {
        Pos curr = q.front();
        q.pop();

        if (curr.y == r - 1 && curr.x == c - 1)
            return curr.dist;

        for (int i = 0; i < 4; i++)
        {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            if (visit[ny][nx])
                continue;
            if (maps[ny][nx] == 0)
                continue;

            visit[ny][nx] = true;
            q.push({ny, nx, curr.dist + 1});
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    return findMinPath(maps);
}