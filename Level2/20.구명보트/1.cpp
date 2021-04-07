// 1.65ms
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int len = people.size();
    int j = len - 1;
    for (int i = 0; i < len; i++)
    {
        if (i > j)
            break;
        if (people[i] + people[j] <= limit)
            j--;
        answer++;
    }
    return answer;
}