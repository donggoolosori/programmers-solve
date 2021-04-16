// 0.2ms
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define MUL 65536

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    unordered_map<string, int> mapA;
    unordered_map<string, int> mapB;
    unordered_set<string> strCollector;

    string combine = "";
    for (int i = 0; i < str1.length() - 1; i++)
    {
        if ((str1[i] >= 'A' && str1[i] <= 'Z') && (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z'))
        {
            combine = str1.substr(i, 2);
            mapA[combine]++;
            strCollector.insert(combine);
        }
    }
    for (int i = 0; i < str2.length() - 1; i++)
    {
        if ((str2[i] >= 'A' && str2[i] <= 'Z') && (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z'))
        {
            combine = str2.substr(i, 2);
            mapB[combine]++;
            strCollector.insert(combine);
        }
    }

    int inter = 0;
    int un = 0;
    for (auto iter : strCollector)
    {
        inter += min(mapA[iter], mapB[iter]);
        un += max(mapA[iter], mapB[iter]);
    }

    if (inter == 0 && un == 0)
        return MUL;
    answer = MUL * inter / un;
    return answer;
}