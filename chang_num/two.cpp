#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long long res = 0;
        bool flag = true;
        bool flag2 = false;
        string temp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-')
            {
                flag = !flag;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                for (int j = i; j < s.length(); j++)
                {
                    if (s[j] >= '0' && s[j] <= '9')
                        temp.push_back(s[j]);
                    else
                    {
                        break;
                    }
                    flag2 = true;
                }
            }
            if (flag2)
            {
                break;
            }
        }
        int cnt = 0;
        while (temp[cnt] == '0')
        {
            cnt++;
        }
        for (int i = cnt; i < temp.length(); i++)
        {
            res = (res * 10 + (temp[i] - '0'));
        }
        if (res >= INT_MAX)
        {
            return INT_MAX;
        }
        else if (res <= INT_MIN)
        {
            return INT_MIN;
        }
        else
        {
            return res;
        }
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("     -42");
    return 0;
}