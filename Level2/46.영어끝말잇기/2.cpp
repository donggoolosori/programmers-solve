// 0.03ms
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<int> getFailureInfo(int idx, int n)
{
    int p_num = idx % n == 0 ? n : idx % n;
    int seq = ceil(double(idx) / n);
    return {p_num, seq};
}

vector<int> solution(int n, vector<string> words)
{
    unordered_set<string> us;
    int p_num, seq;
    int idx = 1;

    string prev = "";
    for (const auto &word : words)
    {
        // 이전 끝단어와 현재 첫단어 다를때
        if (prev != "" && prev.back() != word.front())
            return getFailureInfo(idx, n);
        // 나온적 있는 단어일때
        if (us.count(word))
            return getFailureInfo(idx, n);
        us.insert(word);
        prev = word;
        idx++;
    }
    return {0, 0};
}