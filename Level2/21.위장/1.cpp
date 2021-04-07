// 0.03ms
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> um;
    for (int i = 0; i < clothes.size(); i++)
    {
        um[clothes[i][1]]++;
    }

    for (const auto &iter : um)
    {
        answer *= iter.second + 1;
    }
    answer--;

    return answer;
}