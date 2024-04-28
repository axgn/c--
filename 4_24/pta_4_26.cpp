#include <iostream>
#include <vector>

using namespace std;

int findit(const vector<int> &v, vector<int> &cnt1, int k)
{
    if (cnt1[k - 1] != 0)
    {
        return cnt1[k - 1];
    }
    else
    {
        if (v[k - 1] != -1)
        {
            int temp = findit(v, cnt1, v[k - 1]) + 1;
            cnt1[k - 1] = temp;
            return temp;
        }
        else
        {
            cnt1[k - 1] = 1;
            return 1;
        }
    }
}

int main()
{
    int num;
    cin >> num;
    vector<int> v(num);
    vector<int> cnt1(num);
    int max = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < num; i++)
    {
        findit(v, cnt1, i + 1);
        max = cnt1[i] > max ? cnt1[i] : max;
    }
    cout << max << '\n';
    bool flag = true;
    for (int i = 0; i < num; i++)
    {
        if (cnt1[i] == max)
        {
            if (flag)
            {
                cout << i + 1;
                flag = false;
            }
            else
            {
                cout << ' ' << i + 1;
            }
        }
    }
    return 0;
}