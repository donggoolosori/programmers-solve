// 4505ms
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int timeLine[360000];

int timeToSecond(const string &play_time)
{
    int ret = 0;
    ret += stoi(play_time.substr(0, 2)) * 3600;
    ret += stoi(play_time.substr(3, 2)) * 60;
    ret += stoi(play_time.substr(6, 2));
    return ret;
}

string secondToTime(int second)
{
    int h = second / 3600;
    int m = (second % 3600) / 60;
    int s = (second % 3600) % 60;
    string ret = "";
    if (h < 10)
        ret += "0";
    ret += to_string(h);
    ret += ":";
    if (m < 10)
        ret += "0";
    ret += to_string(m);
    ret += ":";
    if (s < 10)
        ret += "0";
    ret += to_string(s);

    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs)
{

    int limit = timeToSecond(play_time);
    int adv_second = timeToSecond(adv_time);

    for (const string &log : logs)
    {
        int start = timeToSecond(log.substr(0, 8));
        int end = timeToSecond(log.substr(9));
        for (int i = start; i < end; i++)
            timeLine[i]++;
    }

    ll sum = 0;
    int s_idx = 0, idx = 0;
    for (int i = 0; i < adv_second; i++)
        sum += timeLine[i];

    ll maxSum = sum;
    for (int i = adv_second; i < limit; i++)
    {
        sum += timeLine[i];
        sum -= timeLine[s_idx++];
        if (sum > maxSum)
        {
            maxSum = sum;
            idx = i - adv_second + 1;
        }
    }

    string answer = secondToTime(idx);
    return answer;
}