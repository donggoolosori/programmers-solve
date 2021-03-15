#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int cnt, n;
bool Select[8];
bool visit[10000000];

bool isPrime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void findNumbers(string &numbers, string make, int L)
{
    if (make != "")
    {
        int number = stoi(make);
        if (!visit[number])
        {
            visit[number] = true;
            if (isPrime(number))
                cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (Select[i])
            continue;
        Select[i] = true;
        findNumbers(numbers, make + numbers[i], L + 1);
        Select[i] = false;
    }
}

int solution(string numbers)
{
    n = numbers.size();
    findNumbers(numbers, "", 0);
    return cnt;
}