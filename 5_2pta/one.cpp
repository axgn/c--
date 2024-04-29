#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef bool (*fp)(const unordered_map<string, string> &, const string &, const string &);

void read_tree(vector<pair<string, int>> &s_num, int &m)
{
    string s;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int pre_cnt = cnt;
        getline(cin, s);
        while (s[cnt] == ' ')
        {
            cnt++;
        }
        string temp(s.begin() + cnt, s.end());
        s_num.push_back({temp, cnt});
        cnt = 0;
    }
}

void make_map(unordered_map<string, string> &map_parent, const vector<pair<string, int>> &s_num)
{
    stack<int> st;
    int i = 0;
    st.push(i);
    while (!st.empty())
    {
        if (s_num[st.top()].second <= s_num[i + 1].second)
        {
            st.push(i + 1);
            i++;
        }
        else
        {
            int temp = i;
            vector<int> st2;
            while (s_num[temp].second == s_num[st.top()].second)
            {
                st2.push_back(st.top());
                st.pop();
            }
            for (auto &i : st2)
            {
                map_parent[s_num[i].first] = s_num[st.top()].first;
            }
            st.push(i + 1);
            i++;
        }
    }
}

bool child(const unordered_map<string, string> &map_parent, const string &X, const string &Y)
{
    if (map_parent.at(X) == Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool parent(const unordered_map<string, string> &map_parent, const string &X, const string &Y)
{
    if (map_parent.at(Y) == X)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool descendant(const unordered_map<string, string> &map_parent, const string &X, const string &Y)
{
    string temp = X;
    while (map_parent.at(temp) != "")
    {
        if(map_parent.at(temp) == Y)
        {
            return true;
        }
        temp = map_parent.at(temp);
    }
    return false;
}

bool ancestor(const unordered_map<string, string> &map_parent, const string &X, const string &Y)
{
    string temp = Y;
    while (map_parent.at(temp) != "")
    {
        if (map_parent.at(temp) == X)
        {
            return true;
        }
        temp = map_parent.at(temp);
    }
    return false;
}

bool sibling(const unordered_map<string, string> &map_parent, const string &X, const string &Y)
{
    if(map_parent.at(X) == map_parent.at(Y))
    {
        return true;
    }else
    {
        return false;
    }
}

int main()
{
    int m, n;
    string ig;
    unordered_map<string, fp> map_jg = {
        {"child", child},
        {"ancestor", ancestor},
        {"sibling", sibling},
        {"parent", parent},
        {"descendant", descendant}};
    getline(cin, ig);
    istringstream ss(ig);
    ss >> m >> n;
    vector<pair<string, int>> s_num;
    read_tree(s_num, m);
    unordered_map<string, string> map_parent;
    make_map(map_parent, s_num);
    for (int i = 0; i < n; i++)
    {
        string jg;
        getline(cin, jg);
        string s1, s2, s3, s4, s5, s6;
        istringstream ss(jg);
        ss >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
        if (map_jg[s4](map_parent, s1, s6))
        {
            cout << "True\n";
        }
        else
        {
            cout << "False\n";
        }
    }
    for_each(s_num.begin(), s_num.end(), [](auto &k)
             { cout << k.first << ' ' << k.second << '\n'; });
    return 0;
}