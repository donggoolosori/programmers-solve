#include <string>
#include <vector>

using namespace std;
int answer;
void makeTargetNum(int L, vector<int> &numbers, const int &target, int made)
{
    if (L == numbers.size())
    {
        if (made == target)
            answer++;
        return;
    }
    makeTargetNum(L + 1, numbers, target, made + numbers[L]);
    makeTargetNum(L + 1, numbers, target, made - numbers[L]);
}

int solution(vector<int> numbers, int target)
{
    makeTargetNum(0, numbers, target, 0);
    return answer;
}