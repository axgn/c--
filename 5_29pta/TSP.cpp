#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> matrix = {{0, 2, 3, 4, 5},
                              {2, 0, 6, 7, 8},
                              {3, 6, 0, 9, 10},
                              {4, 7, 9, 0, 11},
                              {5, 8, 10, 11, 0}};
std::vector<int> find_path(const std::vector<std::vector<int>> &path, int s, int e)
{
    std::vector<int> res;
    while (path[s][e] != s)
    {
        res.push_back(e);
        e = path[s][e];
    }
    res.push_back(s);
    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> res = {
        1,
    };

    return 0;
}