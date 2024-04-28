#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = temp;
            }
        }
        if (n / 2)
        {
            for (int i = 0; i < n / 2; i++)
            {
                int temp = matrix[n / 2][n - 1 - i];
                matrix[n / 2][n - 1 - i]  = matrix[i][n / 2];
                matrix[i][n / 2] = matrix[n / 2][i];
                matrix[n / 2][i] = matrix[n - 1 - i][n / 2];
                matrix[n - 1 - i][n / 2] = temp;
            }
        }
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(v);
    auto fun = [&](const vector<int> temp)
    { for_each(temp.begin(), temp.end(), [&](const int a)
               { cout << a << ' '; });
               cout << '\n'; };
    for_each(v.begin(), v.end(), fun);
}