#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    answer = number.substr(k);

    for (int i = k - 1; i >= 0; i--)
    {
        int j = 0;
        while (1)
        {
            if (number[i] >= answer[j])
            {
                char temp = number[i];
                number[i] = answer[j];
                answer[j] = temp;
                j++;
            }
            else
                break;
        }
    }

    return answer;
}