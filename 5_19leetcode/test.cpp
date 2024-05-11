#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

void dfs(int i, const vector<vector<int>> &v, int &cnt, int temp, vector<bool> &visited)
{
    if (temp < 6)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (!visited[v[i][j]])
            {
                cnt++;
                visited[v[i][j]] = true;
                dfs(v[i][j], v, cnt, temp + 1, visited);
            }
        }
    }
}

void bfs(int i, const vector<vector<int>> &v, int &cnt, int temp, vector<bool> &visited)
{
    queue<int> q1;
    q1.push(i);
    while (!q1.empty() && temp < 6)
    {
        int temp3 = q1.size();
        for (int k = 0; k < temp3; k++)
        {
            int temp1 = q1.front();
            q1.pop();
            for (int j = 0; j < v[temp1].size(); j++)
            {
                if (!visited[v[temp1][j]])
                {
                    cnt++;
                    q1.push(v[temp1][j]);
                    visited[v[temp1][j]] = true;
                }
            }
        }
        temp++;
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    vector<vector<int>> v(N);
    for (int i = 0; i < E; i++)
    {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 1;
        vector<bool> visited(N, false);
        visited[i] = true;
        bfs(i, v, cnt, 0, visited);
        double res = cnt * 1.0 / v.size();
        cout << i + 1 << ": " << fixed << setprecision(2) << res * 100 << "%\n";
    }
    return 0;
}