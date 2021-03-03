/*
0.01ms

*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check[27];

bool isPossible(queue<char> q, string cand)
{
    for (auto &ch : cand)
    {
        if (!check[ch - 'A'])
            continue;
        if (ch != q.front())
            return false;
        q.pop();
    }
    return true;
}

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    queue<char> q;

    for (const auto &ch : skill)
    {
        q.push(ch);
        check[ch - 'A'] = true;
    }

    for (const auto &s : skill_trees)
        if (isPossible(q, s))
            answer++;

    return answer;
}