#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int computer_devision(int m)
{
    vector<vector<int>> dp(m + 1, {vector<int>(m + 1, 0)});
    dp[1][1] = 1;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i <= m; i++)
    {
        cnt += dp[m][i];
    }
    return cnt;
}

int main()
{
    cout << computer_devision(4);
    return 0;
}