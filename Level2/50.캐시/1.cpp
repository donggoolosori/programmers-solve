#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool isCacheHit(const string &city, deque<string> &dq)
{
    for (const auto &iter : dq)
    {
        if (iter == city)
            return true;
    }
    return false;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    deque<string> dq;

    for (auto &city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        if (isCacheHit(city, dq))
        {
            answer++;
            dq.erase(find(dq.begin(), dq.end(), city));
            dq.push_back(city);
        }
        else
        {
            answer += 5;
            dq.push_back(city);
            if (dq.size() > cacheSize)
                dq.pop_front();
        }
    }
    return answer;
}