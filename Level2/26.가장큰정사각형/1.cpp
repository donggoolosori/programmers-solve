// 3.93ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int r = board.size();
    int c = board[0].size();

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (board[i][j] == 1)
            {
                // (i-1,j-1), (i-1,j), (i,j-1) 순으로 참조해야 속도가 빠르다
                // 2차원 배열에서 같은 행의 데이터는 주소가 연속되기 때문
                board[i][j] = 1 + min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]});
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}