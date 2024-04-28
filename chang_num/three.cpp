#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    vector<string> res;
    string temp = "";
    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void make(string k, int j)
    {
        for (int i = 0; i < s[k[j] - '0'].length(); i++)
        {
            temp.push_back(s[k[j] - '0'][i]);
            if (j < k.length() - 1)
            {
                make(k, j + 1);
            }
            else
            {
                res.push_back(temp);
            }
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        make(digits, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> temp = s.letterCombinations("23");
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    return 0;
}