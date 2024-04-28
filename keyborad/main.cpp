#include <iostream>
#include <deque>
#include <string>

using namespace std;

class Solution
{
public:
    string finalString(string s)
    {
        deque<char> q;
        bool head = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != 'i')
            {
                if (head)
                {
                    q.push_back(s[i]);
                }
                else
                {
                    q.push_front(s[i]);
                }
            }
            else
            {
                head = !head;
            }
        }
        return head ? string{q.begin(), q.end()} : string{q.rbegin(), q.rend()};
    }
};

int main()
{
    string s{"akiegide"};
    Solution s1;
    cout << s1.finalString(s);
    return 0;
}