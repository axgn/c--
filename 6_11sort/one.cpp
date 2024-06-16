#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
            j--;
        }
        a[j + 1] = temp;
        for (int k = 0; k < n; k++)
        {
            if (k < n - 1)
            {
                cout << a[k] << ' ';
            }
            else
            {
                cout << a[k];
                if (i != n - 1)
                {
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}