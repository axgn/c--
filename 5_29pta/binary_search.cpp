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
    vector<int> v = {1, 4, 7, 9, 10, 11, 15, 16, 17};
    int cnt = 0;
    int temp = binary_search(v, 9, cnt);
    if (temp == -1)
    {
        cout << "no found";
    }
    else
    {
        cout << temp << ' ' << cnt << '\n';
    }
    return 0;
}