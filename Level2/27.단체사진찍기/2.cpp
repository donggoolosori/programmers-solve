// 순열 구할때 algorithm 헤더의 next_permutation 사용
// 295.29ms
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isRight(char op, int std, int dist)
{
    if (op == '=')
        return std == dist;
    else if (op == '>')
        return dist > std;
    else
        return dist < std;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    string friends = "ACFJMNRT";

    do
    {
        bool flag = true;
        for (const string &s : data)
        {
            char f1 = s[0];
            char f2 = s[2];
            char op = s[3];
            int std = s[4] - '0';
            int diff = friends.find(f1) - friends.find(f2);
            int dist = abs(diff) - 1;
            if (!isRight(op, std, dist))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}