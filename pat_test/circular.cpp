#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void find_all_target(const string &s, vector<string> &res);
void find_next(const string &substr, vector<int> &next);
void KMP(const string &str, const vector<string> &sub_str);
int main()
{
    int n;
    cin >> n;
    string people_s;
    string vir_s;
    for (int i = 0; i < n; i++)
    {
        cin >> vir_s;
        cin >> people_s;
        vector<string> all_vir;
        find_all_target(vir_s, all_vir);
        KMP(people_s, all_vir);
    }
    return 0;
}

void find_all_target(const string &s, vector<string> &res)
{
    queue<char> q;
    for (auto i : s)
    {
        q.push(i);
    }
    for (int i = 0; i < q.size(); i++)
    {
        string temp;
        for (int i = 0; i < q.size(); i++)
        {
            temp.push_back(q.front());
            q.push(q.front());
            q.pop();
        }
        res.push_back(temp);
        temp.push_back(q.front());
        q.push(q.front());
        q.pop();
    }
}

void find_next(const string &substr, vector<int> &next)
{
    next[0] = -1;
    int left = -1;
    int right = 0;
    while (right < substr.length() - 1)
    {
        if (left == -1 || substr[left] == substr[right])
        {
            left++;
            right++;
            next[right] = left;
        }
        else
        {
            left = next[left];
        }
    }
}

void KMP(const string &str, const vector<string> &sub_str)
{
    int k;
    for (k = 0; k < sub_str.size(); k++)
    {
        vector<int> v(sub_str[k].size());
        find_next(sub_str[k], v);
        int j = 0;
        int i = 0;
        for (; i < str.size() && j < int(sub_str[k].size());)
        {
            if (j == -1 || str[i] == sub_str[k][j])
            {
                i++;
                j++;
            }
            else
            {
                j = v[j];
            }
        }
        if (j >= sub_str[k].size())
        {
            cout << "yes\n";
            break;
        }
    }
    if (k >= sub_str.size())
    {
        cout << "no\n";
    }
}