// 2.04ms
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int r1 = arr1.size(), c1 = arr1[0].size();
    int r2 = arr2.size(), c2 = arr2[0].size();

    for (int i = 0; i < r1; i++)
    {
        vector<int> v;
        for (int j = 0; j < c2; j++)
        {
            int temp = 0;
            for (int k = 0; k < c1; k++)
            {
                temp += arr1[i][k] * arr2[k][j];
            }
            v.push_back(temp);
        }
        answer.push_back(v);
    }
    return answer;
}