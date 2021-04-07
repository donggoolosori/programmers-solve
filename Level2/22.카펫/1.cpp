// 1.9ms, O(N^2)
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    for (int w = 1; w < brown / 2 + 2; w++)
    {
        for (int h = 1; h < brown / 2 + 2; h++)
        {
            if (brown == 2 * (w + h) - 4 && yellow == (w - 2) * (h - 2))
            {
                answer.assign({h, w});
                return answer;
            }
        }
    }
}
