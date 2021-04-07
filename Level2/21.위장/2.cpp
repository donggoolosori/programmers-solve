// 0.03ms
// 굳이 map에 name을 저장할 필요가 없다. 단순히 개수만 세줘도 됨
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, vector<string>> um;

    for (const auto &cloth : clothes)
    {
        string ctg = cloth[1];
        string name = cloth[0];
        um[ctg].push_back(name);
    }
    for (const auto &iter : um)
    {
        answer *= (iter.second.size() + 1);
    }
    answer--;
    return answer;
}