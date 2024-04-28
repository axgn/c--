#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<string> str(0);
        string s_temp;
        for (int i = n1 - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = n2 - 1; j >= 0; j--)
            {
                int temp = (num1[i] - '0') * (num2[j] - '0') + carry;
                s_temp.push_back(temp % 10 + '0');
                carry = temp / 10;
            }
            if (carry > 0)
            {
                s_temp.push_back(carry + '0');
            }
            str.push_back(s_temp);
            s_temp = "";
        }
        for (int i = 0; i < str.size(); i++)
        {
            str[i].resize(205, '0');
        }
        for (int i = 1; i < str.size(); i++)
        {
            int carry = 0;
            for (int j = 0; j < str[i].size(); j++)
            {
                int temp = (str[0][j + i] - '0') + (str[i][j] - '0') + carry;
                str[0][j + i] = temp % 10 + '0';
                carry = temp / 10;
            }
        }
        string res;
        bool flag = false;
        for (int i = str[0].size() - 1; i >= 0; i--)
        {
            if (str[0][i] != '0')
            {
                flag = true;
            }
            if (flag)
            {
                res.push_back(str[0][i]);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    string multiply(string num1, string num2)
    {
        int n1 = num1.size();
        int n2 = num2.size();
        string str1, str2;
        string s_temp;
        bool flag = true;
        int cnt = 1;
        for (int i = n1 - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = n2 - 1; j >= 0; j--)
            {
                int temp = (num1[i] - '0') * (num2[j] - '0') + carry;
                s_temp.push_back(temp % 10 + '0');
                carry = temp / 10;
            }
            if (carry > 0)
            {
                s_temp.push_back(carry + '0');
            }
            if (!flag)
            {
                s_temp.resize(205, '0');
                int carry2 = 0;
                for (int j = 0; j < s_temp.size(); j++)
                {
                    int temp = (s_temp[j] - '0') + (str1[j + cnt] - '0') + carry2;
                    str1[j + cnt] = temp % 10 + '0';
                    carry2 = temp / 10;
                }
                cnt++;
            }
            else
            {
                str1 = s_temp;
                str1.resize(205, '0');
            }
            flag = false;
            s_temp.clear();
        }
        string res;
        flag = false;
        for (int i = str1.size() - 1; i >= 0; i--)
        {
            if (str1[i] != '0')
            {
                flag = true;
            }
            if (flag)
            {
                res.push_back(str1[i]);
            }
        }
        return res;
    }
};

int main()
{
    string s1 = "123";
    string s2 = "456";
    Solution2 s;
    string temp = s.multiply(s1, s2);
    cout << temp;
}