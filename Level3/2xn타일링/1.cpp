// 0.29ms
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{

    vector<int> cache(n + 1);
    cache[1] = 1, cache[2] = 2;
    for (int i = 3; i <= n; i++)
        cache[i] = (cache[i - 1] + cache[i - 2]) % 1000000007;

    return cache[n];
}