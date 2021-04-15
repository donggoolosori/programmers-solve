// 0.04ms
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    unordered_map<string, int> um;
    char head = words[0][0];

    for (int i = 0; i < words.size(); i++)
    {
        // 사람 번호, round 수
        int person = i % n + 1, round = i / n + 1;
        // 앞글자가 다르거나, 이미 나온 단어일 경우
        if (words[i][0] != head || um[words[i]] == 1)
        {
            answer.assign({person, round});
            return answer;
        }
        um[words[i]] = 1;
        head = words[i].back();
    }
    answer.assign({0, 0});
    return answer;
}