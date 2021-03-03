// 0.01ms
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    int check[26] = {
        0,
    };

    // 기준 스킬트리에 포함된 알파벳 체크
    for (const auto &s : skill)
        check[s - 'A'] = 1;

    for (const auto &skill_tree : skill_trees)
    {
        int idx = 0;
        bool flag = true;
        for (const auto &s : skill_tree)
        {
            if (!check[s - 'A'])
                continue;
            if (s == skill[idx])
                idx++;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    }
    return answer;
}