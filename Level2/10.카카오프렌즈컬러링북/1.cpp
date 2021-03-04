// 1.67ms
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int M, N;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
bool visit[100][100];

int dfs(const vector<vector<int>> &picture, int y, int x, int type)
{
    visit[y][x] = true;
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N || visit[ny][nx])
            continue;
        if (picture[ny][nx] != type)
            continue;

        ret += dfs(picture, ny, nx, type);
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    M = m, N = n;
    int countRegions = 0, maxRegion = 0;

    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j] && picture[i][j] != 0)
            {
                countRegions++;
                maxRegion = max(maxRegion, dfs(picture, i, j, picture[i][j]));
            }
        }
    }
    return {countRegions, maxRegion};
}