#include <string>
#include <vector>
#include <algorithm>
#define MAX 201
#define INF 987654321
#define ll long long
using namespace std;

ll dist[MAX][MAX];

void setDist(const int &n, const vector<vector<int>> &fares)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            dist[i][j] = INF;
        }
    }
    for (const auto &fare : fares)
    {
        int a = fare[0], b = fare[1], c = fare[2];
        dist[a][b] = c;
        dist[b][a] = c;
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{

    setDist(n, fares);

    // 플로이드 워셜
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    ll answer = INF;
    // 모든 경유지 고려
    for (int k = 1; k <= n; k++)
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);

    return answer;
}