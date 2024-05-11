#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(const string &s1, const string &s2, int &pos)
{
    int i = 0;
    int j = 0;
    while (i < s1.length())
    {
        int temp = i;
        while (j < s2.length() && s1[temp] == s2[j])
        {
            temp++;
            j++;
        }
        if (j == s2.length())
        {
            pos = i;
            return true;
        }
        else
        {
            i++;
            j = 0;
        }
    }
    return false;
}

int main()
{
    string s1 = "adadf";
    string s2 = "adadf";
    int pos = 1;
    if (check(s1, s2, pos))
    {
        cout << pos;
    }
    return 0;
}