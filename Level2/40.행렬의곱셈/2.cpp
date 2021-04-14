// 2.2ms
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int r = arr1.size(), c = arr2[0].size(), m = arr1[0].size();

    for (int i = 0; i < r; i++)
    {
        vector<int> vec;
        for (int j = 0; j < c; j++)
        {
            int temp = 0;
            for (int k = 0; k < m; k++)
                temp += arr1[i][k] * arr2[k][j];
            vec.push_back(temp);
        }
        answer.push_back(vec);
    }

    return answer;
}