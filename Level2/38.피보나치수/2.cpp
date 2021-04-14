// 3ms
#include <string>
#include <vector>

int fibo[100001];

int getFibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    int &ret = fibo[n];
    if (ret != 0)
        return ret;

    return ret = (getFibo(n - 1) + getFibo(n - 2)) % 1234567;
}

using namespace std;

int solution(int n)
{
    return getFibo(n);
}