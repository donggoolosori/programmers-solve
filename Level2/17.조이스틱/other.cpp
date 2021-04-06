#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LUT[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int solution(string name)
{
    int answer = 0;
    int len = name.length();

    // 위 아래 이동 계산
    for (auto ch : name)
        answer += LUT[ch - 'A'];

    int left_right = len - 1; // 좌우 이동 거리

    for (int i = 0; i < len; ++i)
    {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        // case1) o -> i -> o -> ni  = i + i + len - next_i
        // case2) o -> ni -> o -> i = (len-next_i) + (len-next_i) + i
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}