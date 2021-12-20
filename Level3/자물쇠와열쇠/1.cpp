// 17.43ms
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int keySize, lockSize, boardSize;

// key를 90도 회전
void rotateKey(vector<vector<int>> &key)
{
    reverse(key.begin(), key.end());
    for (int i = 0; i < keySize; i++)
        for (int j = i + 1; j < keySize; j++)
            swap(key[i][j], key[j][i]);
}

// 좌물쇠가 열리는지 확인
bool isOpen(int y, int x, vector<vector<int>> key, vector<vector<int>> board)
{
    // key를 board에 더하기
    for (int i = y; i < y + keySize; i++)
        for (int j = x; j < x + keySize; j++)
            board[i][j] += key[i - y][j - x];

    // 좌물쇠 부분 확인
    for (int i = keySize - 1; i <= boardSize - keySize; i++)
    {
        for (int j = keySize - 1; j <= boardSize - keySize; j++)
        {
            if (board[i][j] != 1)
                return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    keySize = key.size(), lockSize = lock.size();
    boardSize = lockSize + (keySize - 1) * 2;

    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    // board에 lock 넣기
    for (int i = keySize - 1; i <= boardSize - keySize; i++)
        for (int j = keySize - 1; j <= boardSize - keySize; j++)
            board[i][j] = lock[i - keySize + 1][j - keySize + 1];

    // 회전
    for (int i = 0; i < 4; i++)
    {
        // 키의 위치를 바꿔가며 키, 자물쇠 맞춰보기
        for (int y = 0; y <= boardSize - keySize; y++)
        {
            for (int x = 0; x <= boardSize - keySize; x++)
            {
                if (isOpen(y, x, key, board))
                    return true;
            }
        }
        if (i != 3)
            rotateKey(key);
    }

    return false;
}