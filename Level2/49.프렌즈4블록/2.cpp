// 1.45ms
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos
{
    int y, x;
};
int dy[4] = {0, 0, 1, 1};
int dx[4] = {0, 1, 0, 1};
int height[30];

int solution(int m, int n, vector<string> board)
{
    queue<Pos> q;
    int cnt = 0;

    while (true)
    {
        // 지우기
        while (!q.empty())
        {
            Pos curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = curr.y + dy[i];
                int nx = curr.x + dx[i];
                if (board[ny][nx] != '*')
                {
                    cnt++;
                    board[ny][nx] = '*';
                }
            }
        }
        // 블록 떨어뜨리기
        for (int c = 0; c < n; c++)
        {
            for (int r = m - 1; r > 0; r--)
            {
                if (board[r][c] == '*')
                {
                    for (int k = r - 1; k >= 0; k--)
                    {
                        if (board[k][c] != '*')
                        {
                            swap(board[k][c], board[r][c]);
                            break;
                        }
                    }
                }
            }
        }

        // 지울수 있는 4블록의 왼쪽 위 좌표 찾기
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == '*')
                    continue;
                char curr = board[i][j];
                if (curr == board[i][j + 1] && curr == board[i + 1][j] && curr == board[i + 1][j + 1])
                    q.push({i, j});
            }
        }
        if (q.empty())
            break;
    }

    return cnt;
}