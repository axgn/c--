#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

template <>
struct std::hash<vector<int>>
{
    size_t operator()(const vector<int> &temp) const noexcept
    {
        int seed = temp.size();
        for (auto &i : temp)
        {
            seed ^= size_t(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

int main()
{
    unordered_map<vector<int>, int> a;
    unordered_set<vector<int>> k;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 4};
    a[v1] = 5;
    a[v2] = 4;
    a.insert({v1, 5});
    k.insert(v1);
    k.insert(v2);
    function<void(int)> fun1 = [](int a)
    { cout << a << ' '; };
    for (auto &i : k)
    {
        for_each(i.begin(), i.end(), fun1);
        cout << '\n';
    }
    cout << a[v1];
    return 0;
}