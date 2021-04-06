#include <string>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int len = number.length();
    int index = -1;

    for (int i = 0; i < len - k; i++)
    {
        char temp = '0';
        for (int j = index + 1; j <= k + i; j++)
        {
            if (temp < number[j])
            {
                index = j;
                temp = number[j];
            }
        }
        answer += temp;
    }

    return answer;
}