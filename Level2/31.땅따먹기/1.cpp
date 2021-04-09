#include <iostream>
#include <vector>
using namespace std;

int hopscotch(vector<vector<int>> board)
{
    int max_1;
    int max_2;
    int max_index;
    for (int i = 0; i < board.size() - 1; i++)
    {
        max_1 = 0;
        max_2 = 0;
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] > max_1)
            {
                max_2 = max_1;
                max_1 = board[i][j];
                max_index = j;
            }
            else if (board[i][j] > max_2)
                max_2 = board[i][j];
        }
        for (int j = 0; j < board[i].size(); j++)
        {
            if (j != max_index)
                board[i + 1][j] += max_1;
            else
                board[i + 1][j] += max_2;
        }
    }
    max_1 = 0;
    for (int i = 0; i < 4; i++)
        if (board[board.size() - 1][i] > max_1)
            max_1 = board[board.size() - 1][i];

    return max_1;
}

int main()
{
    vector<vector<int>> test{{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
    //아래는 테스트로 출력해 보기 위한 코드입니다.
    cout << hopscotch(test);
}