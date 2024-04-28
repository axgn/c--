#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a{4, 5, 9, 1, 10, 23};
    vector<int> b{4, 5, 6, 7, 8, 9, 10, 56, 23};
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int>::iterator it_a = a.begin();
    vector<int>::iterator it_b = b.begin();
    while (it_a != a.end() && it_b != b.end())
    {
        if (*it_a > *it_b)
        {
            it_b++;
        }
        else if (*it_a < *it_b)
        {
            it_a++;
        }
        else
        {
            it_a = a.erase(it_a);
        }
    }
    if (!a.empty())
    {
        for (auto i : a)
        {
            cout << i << ' ';
        }
    }
    else
    {
        cout << 0;
    }
    return 0;
}