#include <algorithm>

using namespace std;

long long solution(int w, int h)
{
    long long answer = (long long)w * (long long)h;
    int a = w, b = h;
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    int gcd = a;

    answer -= gcd * (w / gcd + h / gcd - 1);
    return answer;
}