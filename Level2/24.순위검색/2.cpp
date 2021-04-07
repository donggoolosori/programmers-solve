/*
810.52ms
4차원 array사용
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> db[3][2][2][2];

vector<int> splitInfo(const string &s)
{
    vector<int> ret;
    string temp;
    int n;
    for (const auto &ch : s)
    {
        // 공백 만남
        if (ch == ' ')
        {
            if (temp == "cpp" || temp == "backend" || temp == "junior" || temp == "chicken")
                n = 0;
            else if (temp == "python")
                n = 2;
            else
                n = 1;
            ret.push_back(n);
            temp = "";
        }
        else
            temp += ch;
    }
    ret.push_back(stoi(temp));
    return ret;
}

vector<string> splitQuery(const string &s)
{
    vector<string> ret;

    string temp;
    for (const auto &ch : s)
    {
        if (ch == ' ')
        {
            if (temp != "and")
                ret.push_back(temp);
            temp = "";
        }
        else
            temp += ch;
    }
    // score 저장
    ret.push_back(temp);
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    // set db
    for (const string &s : info)
    {
        vector<int> v = splitInfo(s);
        db[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }

    // 정렬 수행
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end(), greater<int>());
    // 쿼리 수행
    for (const auto &s : query)
    {
        vector<string> v = splitQuery(s);

        // 탐색 범위 좁히기
        int from_i, to_i, from_j, to_j, from_k, to_k, from_l, to_l;
        // 언어
        if (v[0] == "cpp")
            from_i = to_i = 0;
        else if (v[0] == "java")
            from_i = to_i = 1;
        else if (v[0] == "python")
            from_i = to_i = 2;
        else
        {
            from_i = 0;
            to_i = 2;
        }

        // back or front
        if (v[1] == "backend")
            from_j = to_j = 0;
        else if (v[1] == "frontend")
            from_j = to_j = 1;
        else
        {
            from_j = 0;
            to_j = 1;
        }

        // junior senior
        if (v[2] == "junior")
            from_k = to_k = 0;
        else if (v[2] == "senior")
            from_k = to_k = 1;
        else
            from_k = 0, to_k = 1;

        // food
        if (v[3] == "chicken")
            from_l = to_l = 0;
        else if (v[3] == "pizza")
            from_l = to_l = 1;
        else
            from_l = 0, to_l = 1;

        int cnt = 0;
        int score_std = stoi(v[4]);
        // 탐색
        for (int i = from_i; i <= to_i; i++)
            for (int j = from_j; j <= to_j; j++)
                for (int k = from_k; k <= to_k; k++)
                    for (int l = from_l; l <= to_l; l++)
                        for (int iter : db[i][j][k][l])
                        {
                            if (iter < score_std)
                                break;
                            cnt++;
                        }

        answer.push_back(cnt);
    }

    return answer;
}