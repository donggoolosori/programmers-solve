#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void step1(string &id)
{
    transform(id.begin(), id.end(), id.begin(), ::tolower);
}

void step2(string &id)
{
    string temp = "";
    for (const char &ch : id)
    {
        if (isdigit(ch) || (ch >= 'a' && ch <= 'z') || ch == '-' || ch == '_' || ch == '.')
            temp += ch;
    }
    id = temp;
}

void step3(string &id)
{
    string temp = "";
    for (int i = 0; i < id.length(); i++)
    {
        temp += id[i];
        if (id[i] == '.')
        {
            while (i + 1 < id.length() && id[i + 1] == '.')
                i++;
        }
    }
    id = temp;
}

void step4(string &id)
{
    if (id[0] == '.')
        id.erase(0, 1);
    if (id.back() == '.')
        id.pop_back();
}

void step5(string &id)
{
    if (id.length() == 0)
        id = "a";
}

void step6(string &id)
{
    if (id.length() >= 16)
        id.erase(15);
    while (id.back() == '.')
        id.pop_back();
}

void step7(string &id)
{
    if (id.length() <= 2)
    {
        char it = id.back();
        while (id.length() < 3)
            id += it;
    }
}

string solution(string new_id)
{
    step1(new_id);
    step2(new_id);
    step3(new_id);
    step4(new_id);
    step5(new_id);
    step6(new_id);
    step7(new_id);

    return new_id;
}