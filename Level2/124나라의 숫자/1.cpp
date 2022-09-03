#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string s = "";

    while (n > 0)
    {
        if (n % 3 == 0)
        {
            s = "4" + s;
            n = n / 3 - 1;
        }
        else
        {
            s = to_string(n % 3) + s;
            n /= 3;
        }
    }
    return s;
}