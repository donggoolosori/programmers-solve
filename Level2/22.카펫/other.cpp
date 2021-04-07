// 0.01ms, O(N)
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int sumOfWH = brown / 2 + 2;
    int h = 3;
    int w = sumOfWH - 3;
    while (w >= h)
    {
        if ((w - 2) * (h - 2) == yellow)
            break;
        w--;
        h++;
    }
    return {w, h};
}