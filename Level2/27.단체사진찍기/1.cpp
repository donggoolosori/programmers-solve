/*
test case는 통과
실행시 런타임 에러
*/
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

struct Cond
{
    char a, b, op;
    int dist;
};

bool visited[26];
char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
int cnt = 0;
int N;

void setConds(vector<string> &data, vector<Cond> &conds)
{
    for (int i = 0; i < N; i++)
    {
        Cond newCond;
        newCond.a = data[i][0];
        newCond.b = data[i][2];
        newCond.op = data[i][3];
        newCond.dist = data[i][4] - '0';
        conds.push_back(newCond);
    }
}

bool isRight(const string &s, vector<Cond> &conds)
{
    for (int i = 0; i < N; i++)
    {
        Cond cond = conds[i];
        int f1 = s.find(cond.a);
        int f2 = s.find(cond.b);
        int dist = abs(f1 - f2) - 1;

        if (cond.op == '=')
        {
            if (dist > 0)
                return false;
        }
        else if (cond.op == '>')
        {
            if (dist <= cond.dist)
                return false;
        }
        else
        {
            if (dist >= cond.dist)
                return false;
        }
    }
    return true;
}

void findCases(int L, string s, vector<Cond> &conds)
{
    if (L == 8)
    {
        if (isRight(s, conds))
            cnt++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (visited[friends[i] - 'A'])
            continue;
        visited[friends[i] - 'A'] = true;
        findCases(L + 1, s + friends[i], conds);
        visited[friends[i] - 'A'] = false;
    }
}

int solution(int n, vector<string> data)
{
    // 전역변수 초기화
    memset(visited, false, sizeof(visited));
    cnt = 0;
    N = n;

    vector<Cond> conds;
    setConds(data, conds);
    findCases(0, "", conds);

    return cnt;
}