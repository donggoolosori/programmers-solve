// 0.3ms
// substr을 사용하는게 더 빠른듯
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#define MUL 65536

using namespace std;

unordered_map<string, int> um1;
unordered_map<string, int> um2;
unordered_set<string> st;

// 알파벳으로 이루어져 있는지 check
bool isAlp(string s)
{
    for (const auto &ch : s)
        if (ch < 'a' || ch > 'z')
            return false;
    return true;
}

// 집합 만들기
void makeSet(const string &s1, const string &s2)
{
    string temp = "";
    temp += s1[0];
    for (int i = 1; i < s1.length(); i++)
    {
        temp += s1[i];
        if (isAlp(temp))
        {
            cout << temp << '\n';

            st.insert(temp);
            um1[temp]++;
        }
        temp = "";
        temp += s1[i];
    }

    temp = "";
    temp += s2[0];
    for (int i = 1; i < s2.length(); i++)
    {
        temp += s2[i];
        if (isAlp(temp))
        {
            cout << temp << '\n';
            st.insert(temp);
            um2[temp]++;
        }
        temp = "";
        temp += s2[i];
    }
}

int getJC()
{
    if (st.empty())
        return MUL;
    int total = 0, inter = 0;

    for (const auto &s : st)
    {
        total += max(um1[s], um2[s]);
        inter += min(um1[s], um2[s]);
    }

    return MUL * inter / total;
}

int solution(string str1, string str2)
{
    // 소문자로 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    // 집합 구하기
    makeSet(str1, str2);
    // 자카드 유사도 구하기
    return getJC();
}