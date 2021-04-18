// 1.64ms
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos
{
    int y, x;
};
int dy[4] = {0, 0, -1, -1};
int dx[4] = {0, -1, 0, -1};

void fall(int m, int n, vector<string> &board)
{
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
                        board[r][c] = board[k][c];
                        board[k][c] = '*';
                        break;
                    }
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    queue<Pos> q;
    while (true)
    {
        while (!q.empty())
        {
            Pos cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (board[ny][nx] != '*')
                {
                    answer++;
                    board[ny][nx] = '*';
                }
            }
        }

        fall(m, n, board);

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (board[i][j] == '*')
                    continue;
                char cur = board[i][j];
                if (cur == board[i - 1][j - 1] && cur == board[i - 1][j] && cur == board[i][j - 1])
                {
                    q.push({i, j});
                }
            }
        }
        if (q.empty())
            break;
    }
    return answer;
}