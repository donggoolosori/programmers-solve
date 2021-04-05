#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// order에서 가능한 c개로 이루어진 course 모두 찾기
void findCourse(const string &order, unordered_map<string, int> &um, string curr, int L, int index, int c)
{
    if (L == c)
    {
        um[curr]++;
        return;
    }

    for (int i = index; i < order.length(); i++)
        findCourse(order, um, curr + order[i], L + 1, i + 1, c);
}

// 정렬 기준
bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (const auto &c : course)
    {

        unordered_map<string, int> um;
        for (auto order : orders)
        {
            sort(order.begin(), order.end());
            findCourse(order, um, "", 0, 0, c);
        }

        // um을 int 기준 내림차순 정렬
        if (um.empty())
            continue;
        vector<pair<string, int>> v(um.begin(), um.end());
        sort(v.begin(), v.end(), compare);

        // 가장 int 값이 큰 녀석들만 answer 배열에 추가
        int std = v[0].second;
        if (std >= 2)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].second == std)
                    answer.push_back(v[i].first);
                else
                    break;
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}