#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> mp;

void selectMenu(const int &c, const string &order, int L, int idx, string made)
{
    if (L == c)
    {
        mp[made]++;
        return;
    }
    for (int i = idx; i < order.length(); i++)
        selectMenu(c, order, L + 1, i + 1, made + order[i]);
}

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course)
{

    vector<string> answer;
    for (const auto &c : course)
    {
        mp.clear();
        for (string &order : orders)
        {
            sort(order.begin(), order.end());
            selectMenu(c, order, 0, 0, "");
        }
        vector<pair<string, int>> temp(mp.begin(), mp.end());
        sort(temp.begin(), temp.end(), compare);

        if (temp.size() == 0 || temp[0].second < 2)
            continue;
        int maxCnt = temp[0].second;

        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].second == maxCnt)
                answer.push_back(temp[i].first);
            else
                break;
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}