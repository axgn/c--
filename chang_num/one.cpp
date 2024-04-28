#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool flag = true;
        if (x > 999999999 || x < -999999999)
        {
            if (x == INT_MIN)
            {
                return 0;
            }
            if (x < 0)
            {
                x = -x;
                flag = false;
            }
            string s = to_string(x);
            string s1 = to_string(INT_MAX);
            std::reverse(s.begin(), s.end());
            if (s > s1)
            {
                return 0;
            }
            else
            {
                return flag ? -stoi(s) : stoi(s);
            }
        }
        else
        {
            if (x < 0)
            {
                x = -x;
                flag = false;
            }
            string s = to_string(x);
            string s1 = to_string(INT_MAX);
            std::reverse(s.begin(), s.end());
            return flag ? -stoi(s) : stoi(s);
        }
    }
};

int main()
{
    Solution s;
    s.reverse(5);
    return 0;
}
