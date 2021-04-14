// 0.01ms
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 유클리드 호제법 , a>=b
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int solution(vector<int> arr)
{
    int len = arr.size();
    if (len == 1)
        return arr[0];

    int answer = arr[0];
    for (int i = 1; i < len; i++)
    {
        int b = answer, a = arr[i];
        if (a < b)
            swap(a, b);
        answer = a * b / gcd(a, b);
    }

    return answer;
}