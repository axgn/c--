#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs1(const vector<vector<int>> &v, int now, vector<int> &visited)
{
    cout << now << ' ';
    visited[now] = 1;
    for (int i = 0; i < v[now].size(); i++)
    {
        if (!visited[i] && v[now][i] == 1)
        {
            dfs1(v, i, visited);
        }
    }
}

void dfs2(const vector<vector<int>> &v, int now, vector<int> &visited)
{
    stack<int> st;
    vector<stack<int>> i_cnt;
    st.push(now);
    cout << now << ' ';
    visited[now] = 1;
    for (int i = 0; i < v[now].size(); i++)
    {
        if (!visited[i] && v[now][i] == 1)
        {
            st.push(i);
            now = st.top();
            st.pop();
        }
    }
}

int main()
{
    vector<vector<int>> graph(6, vector<int>(6, 0));
    int n;
    for (int i = 0; i < graph.size(); i++)
    {
        for (auto j : graph[i])
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s_edge, e_edge;
        cin >> s_edge >> e_edge;
        graph[s_edge][e_edge] = 1;
        graph[e_edge][s_edge] = 1;
    }
    vector<int> visited(6, 0);
    dfs1(graph, 0, visited);
    return 0;
}