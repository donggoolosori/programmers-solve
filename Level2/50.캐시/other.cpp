// 28.4ms
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int cacheSize, vector<string> cities)
{

    vector<string> q;
    int duration = 0;

    for (vector<string>::iterator it = cities.begin(); it != cities.end(); it++)
    {
        transform(it->begin(), it->end(), it->begin(), ::tolower);

        bool flag = false;
        for (vector<string>::iterator itt = q.begin(); itt != q.end(); itt++)
        {
            if (*itt == *it)
            {
                flag = true;
                duration += 1;
                q.erase(itt);
                q.push_back(*it);
                break;
            }
        }
        if (!flag)
        {
            duration += 5;
            if (cacheSize != 0 && q.size() >= cacheSize)
                q.erase(q.begin());
            if (q.size() < cacheSize)
                q.push_back(*it);
        }
    }

    return duration;
}