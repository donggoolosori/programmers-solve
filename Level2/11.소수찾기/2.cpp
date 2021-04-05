#include <string>
#include <vector>
#include <cmath>
#define MAX 10000000

using namespace std;

bool isSelected[8];
bool visited[MAX];
int cnt;

bool isPrime(const int &num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

void findNumOfPrime(const string &numbers, string curr)
{
    if (curr != "")
    {
        int num = stoi(curr);
        if (!visited[num])
        {
            visited[num] = true;

            if (isPrime(num))
                cnt++;
        }
    }

    for (int i = 0; i < numbers.length(); i++)
    {
        if (isSelected[i])
            continue;
        isSelected[i] = true;
        findNumOfPrime(numbers, curr + numbers[i]);
        isSelected[i] = false;
    }
}

int solution(string numbers)
{
    findNumOfPrime(numbers, "");

    return cnt;
}