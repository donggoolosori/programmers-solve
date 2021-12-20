// 5.2ms
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 9;

void getMinNumOfCal(int N, int number, int L, int curr)
{

    if (L > 8)
        return;

    if (curr == number)
    {
        answer = min(answer, L);
        return;
    }

    int temp = 0;
    for (int i = 0; L + i < 9; i++)
    {
        temp = temp * 10 + N;
        getMinNumOfCal(N, number, L + 1 + i, curr + temp);
        getMinNumOfCal(N, number, L + 1 + i, curr - temp);
        getMinNumOfCal(N, number, L + 1 + i, curr * temp);
        getMinNumOfCal(N, number, L + 1 + i, curr / temp);
    }
}

int solution(int N, int number)
{

    getMinNumOfCal(N, number, 0, 0);
    if (answer == 9)
        return -1;
    return answer;
}