// 2.61ms
#include <string>
#include <vector>

using namespace std;

int fibo[100000];

int getFibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (fibo[n] != 0)
        return fibo[n];
    else
        return fibo[n] = (getFibo(n - 1) + getFibo(n - 2)) % 1234567;
}

int solution(int n)
{
    int answer = getFibo(n);

    return answer;
}