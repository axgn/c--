#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void solution1(stringstream &ss)
{
    string s;
    ss >> s;
    string s2;
    s2 = s;
    reverse(s.begin(), s.end());
    if (s == s2)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}

void solution2(stringstream &ss)
{
    vector<string> v;
    string temp;
    while (ss >> temp)
    {
        v.push_back(temp);
    }
    reverse(v.begin(), v.end());
    if (!v.empty())
    {
        cout << v.front();
    }
    for (int i = 1; i < v.size(); i++)
    {
        cout << ' ' << v[i];
    }
}

void solution3(stringstream &ss)
{
    int n;
    int mi, ma;
    ss >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        ss >> v[i];
    }
    ss >> mi >> ma;
    auto it = v.begin();
    for (; it != v.end(); it++)
    {
        int temp = *it;
        if (temp >= mi && temp <= ma)
        {
            it = v.erase(it) - 1;
        }
    }
    if (!v.empty())
    {
        cout << v.front();
    }
    for (int i = 1; i < v.size(); i++)
    {
        cout << ' ' << v[i];
    }
}

void solution4(stringstream &ss)
{
}

int main()
{
    stringstream ss1("abcba");
    stringstream ss2("how   are   you");
    stringstream ss3("5\n40 34 89 23 10\n30 40");
    solution1(ss1);
    cout << '\n';
    solution2(ss2);
    cout << '\n';
    solution3(ss3);
    cout << '\n';
    return 0;
}