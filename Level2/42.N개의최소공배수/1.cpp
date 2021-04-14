// 0.02ms
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getGcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return getGcd(b, a % b);
}

int solution(vector<int> arr)
{
    int answer = arr[0];
    int gcd;

    for (int i = 1; i < arr.size(); i++)
    {
        gcd = answer < arr[i] ? getGcd(arr[i], answer) : getGcd(answer, arr[i]);
        answer = arr[i] * answer / gcd;
    }
    return answer;
}