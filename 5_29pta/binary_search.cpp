#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int binary_search(vector<T> v, T des, int &cnt)
{
    int left = 0;
    int right = int(v.size()) - 1;
    while (left <= right)
    {
        cnt++;
        int mid = (left + right) / 2;
        if (v[mid] == des)
        {
            return mid;
        }
        else if (v[mid] > des)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> n;
    int cnt = 0;
    int temp = binary_search(v, n, cnt);
    cout << temp << '\n';
    cout << cnt << '\n';
    return 0;
}