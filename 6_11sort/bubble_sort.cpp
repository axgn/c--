#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v, int i, bool flag)
{
    int n = v.size();
    for (int k = 0; k < n; k++)
    {
        if (k < n - 1)
        {
            cout << v[k] << ' ';
        }
        else
        {
            cout << v[k];
            if (i == n - 1 || !flag)
            {
                continue;
            }
            cout << '\n';
        }
    }
}

int main()
{
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = n - 1; i >= 1; i--)
    {
        bool flag = false;
        for (size_t j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
        print(a, i, flag);
    }
    return 0;
}