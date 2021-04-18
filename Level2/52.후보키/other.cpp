// 0.71ms
#include <string>
#include <vector>
#include <set>

using namespace std;

// 최소성 검사
bool check(vector<int> &ans, int num)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if ((ans[i] & num) == ans[i])
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation)
{
    int r = relation.size();
    int c = relation[0].size();
    vector<int> ans;

    for (int i = 0; i < (1 << c); i++)
    {
        set<string> s;

        if (!check(ans, i))
            continue;
        for (int j = 0; j < r; j++)
        {
            string temp = "";

            for (int k = 0; k < c; k++)
            {
                if (i & (1 << k))
                    temp += relation[j][k];
            }
            s.insert(temp);
        }

        if (s.size() == r)
            ans.push_back(i);
    }
    return ans.size();
}