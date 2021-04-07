// 3.74ms
#include <string>
#include <vector>

using namespace std;

int zero, one;

void zip(vector<vector<int>> &arr, int y, int x, int size)
{
    int cur = arr[y][x];

    bool flag = true;
    for (int i = y; i < y + size; i++)
    {
        if (!flag)
            break;
        for (int j = x; j < x + size; j++)
        {
            if (arr[i][j] != cur)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cur == 0 ? zero++ : one++;
        return;
    }
    zip(arr, y, x, size / 2);
    zip(arr, y, x + size / 2, size / 2);
    zip(arr, y + size / 2, x, size / 2);
    zip(arr, y + size / 2, x + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr)
{
    zip(arr, 0, 0, arr.size());
    return {zero, one};
}