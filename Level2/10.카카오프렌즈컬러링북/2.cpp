// 1.67ms
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
bool visit[100][100];

int dfs(const vector<vector<int>> &picture, int m, int n, int y, int x, int type)
{
    visit[y][x] = true;
    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n || visit[ny][nx])
            continue;
        if (picture[ny][nx] != type)
            continue;

        ret += dfs(picture, m, n, ny, nx, type);
    }

    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    // 전역변수 visit 초기화
    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j] && picture[i][j] != 0)
            {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, dfs(picture, m, n, i, j, picture[i][j]));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}