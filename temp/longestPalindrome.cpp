#include <iostream>
#include <string>
#include<limits>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int max_length1 = 1;
        int cnt = 1;
        string temp1;
        for (int i = 0; i < s.length(); i++)
        {
            int j;
            for (j = 1; i - j > -1 && i + j < s.length(); j++)
            {
                if (s[i - j] == s[i + j])
                {
                    cnt += 2;
                }
                else
                {
                    break;
                }
            }
            j = j - 1;
            if (cnt > max_length1)
            {
                temp1 = s.substr(i - j, 2 * j + 1);
                max_length1 = cnt;
            }
            cnt = 1;
        }
        if(temp1 == "")
        {
            temp1 = s.substr(0,1);
        }
        max_length1 = (max_length1 - 1) * 2 + 1;
        cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j;
            for (j = 0; i - j > -1 && i + j < s.length(); j++)
            {
                if (s[i + j] == s[i + 1 + j])
                {
                    cnt += 2;
                }
                else
                {
                    break;
                }
            }
            if (cnt > max_length1)
            {
                temp1 = s.substr(i - j + 1, 2 * j);
                max_length1 = cnt;
            }
            cnt = 0;
        }
        return temp1;
    }
};

int main()
{
    Solution s;
    string str = "cbbd";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}