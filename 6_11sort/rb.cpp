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

void merge2(vector<int> &v, int s, int e)
{
    int mid = (s + e) / 2;
    vector<int> temp = v;
    int a = s, b = mid + 1;
    int temp1 = s;
    while (a <= mid && b <= e)
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
    if (a <= mid)
    {
        for (int i = a; i <= mid; i++)
        {
            temp[temp1] = v[i];
            temp1++;
        }
    }
    if (b <= e)
    {
        for (int i = b; i <= e; i++)
        {
            temp[temp1] = v[i];
            temp1++;
        }
    }
    v = temp;
}

void Msort(vector<int> &v, int left, int right)
{
    if (left == right)
    {
        return;
    }
    else
    {
        int mid = (left + right) / 2;
        Msort(v, left, mid);
        Msort(v, mid + 1, right);
        merge(v, left, mid, mid + 1, right);
    }
}

void mergesort(vector<int> &v)
{
    Msort(v, 0, v.size() - 1);
}

int main()
{
    size_t n;
    cin >> n;
    vector<int> a(n);
    stack<int> right;
    stack<int> left;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    left.push(0);
    right.push(a.size() - 1);
    int l = left.top();
    int r = right.top();
    while (l != r)
    {
        int mid = (l + r) / 2;
        left.push(l);
        right.push(mid);
        l = left.top();
        r = right.top();
    }
    left.pop();
    right.pop();
    mergesort(a);
    print(a);
    return 0;
}