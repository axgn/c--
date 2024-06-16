#include <iostream>
#include <vector>
#include <stack>

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

void merge(vector<int> &v, int s_a, int e_a, int s_b, int e_b)
{
    vector<int> temp = v;
    int a = s_a, b = s_b;
    int temp1 = s_a;
    while (a <= e_a && b <= e_b)
    {
        if (v[a] < v[b])
        {
            temp[temp1] = v[a];
            a++;
        }
        else
        {
            temp[temp1] = v[b];
            b++;
        }
        temp1++;
    }
    if (a <= e_a)
    {
        for (int i = a; i <= e_a; i++)
        {
            temp[temp1] = v[i];
            temp1++;
        }
    }
    if (b <= e_b)
    {
        for (int i = b; i <= e_b; i++)
        {
            temp[temp1] = v[i];
            temp1++;
        }
    }
    v = temp;
}

int main()
{
    vector<int> a = {2, 12, 16, 30, 10, 16, 20, 28, 6, 18};
    size_t n = a.size();
    for (int i = 1; i <= 4; i++)
    {
        int step = 1 << i;
        for (int j = 0; j < n; j += step)
        {
            merge(a, j, j + step / 2 - 1, j + step / 2, min(j + step - 1, int(n - 1)));
        }
        print(a);
    }
    return 0;
}