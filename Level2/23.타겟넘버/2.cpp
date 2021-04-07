#include <string>
#include <vector>

using namespace std;

int answer;

void setNumOfCases(const vector<int> &numbers, const int &target, int L, int curr)
{
    if (L == numbers.size())
    {
        if (curr == target)
            answer++;

        return;
    }
    setNumOfCases(numbers, target, L + 1, curr + numbers[L]);
    setNumOfCases(numbers, target, L + 1, curr - numbers[L]);
}

int solution(vector<int> numbers, int target)
{
    setNumOfCases(numbers, target, 0, 0);
    return answer;
}