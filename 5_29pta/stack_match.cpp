#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string push_st_v{"ABCDEF"};
    string pop_st_v{"DCEFAB"};
    stack<char> st;
    int push_pos = 0;
    int pop_pos = 0;
    while (push_pos < push_st_v.size() && pop_pos < pop_st_v.size())
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
    if (!st.empty())
    {
        cout << "no" << '\n';
    }
    else
    {
        cout << "yes" << '\n';
    }
    return 0;
}