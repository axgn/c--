#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
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
            cout << '\n';
        }
    }
}

bool check(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            return false;
        }
    }
    return true;
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
    for (size_t i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (size_t j = i; j < n; j++)
        {
            if (a[j] < a[temp])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            int temp1 = a[temp];
            a[temp] = a[i];
            a[i] = temp1;
        }
        print(a);
    }
    return 0;
}