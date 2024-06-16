#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string push_st_v;
        string pop_st_v;
        cin >> push_st_v >> pop_st_v;
        stack<char> st;
        int push_pos = 0;
        int pop_pos = 0;
        while (push_pos < push_st_v.size())
        {
            st.push(push_st_v[push_pos]);
            cout << "push:" << st.top() << '\n';
            while (!st.empty() && st.top() == pop_st_v[pop_pos])
            {
                st.pop();
                cout << "pop:" << pop_st_v[pop_pos] << '\n';
                pop_pos++;
            }
            push_pos++;
        }
        if (!st.empty() || pop_st_v.size() != pop_pos)
        {
            cout << "no";
        }
        else
        {
            cout << "yes";
        }
        if(i != n - 1)
        {
            cout << '\n';
        }
    }
    return 0;
}