#include <string>
#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    string str;
    getline(cin, str);
    int n;
    string sub_str = "abababab";
    vector<int> next(sub_str.size());
    find_next(sub_str, next);
    for (auto i : next)
    {
        cout << i << ' ';
    }
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        cin >> sub_str;
        vector<int> v(sub_str.size());
        find_next(sub_str, v);
        int j = 0;
        int i = 0;
        for (; i < str.size() && j < int(sub_str.size());)
        {
            if (j == -1 || str[i] == sub_str[j])
            {
                i++;
                j++;
            }
            else
            {
                j = v[j];
            }
        }
        if (j >= sub_str.size())
        {
            for (int m = i - sub_str.size(); m < str.size(); m++)
            {
                cout << str[m];
            }
        }
        else
        {
            cout << "Not Found";
        }
        if (k != n - 1)
        {
            cout << '\n';
        }
    }
    return 0;
}