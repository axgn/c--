#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int money;
    int start;
    int end;
};

bool check(const vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] != v[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<edge> ed(M);
    vector<int> result;
    for (int i = 0; i < M; i++)
    {
        cin >> ed[i].start >> ed[i].end >> ed[i].money;
        ed[i].start--;
        ed[i].end--;
    }
    vector<int> vexset(N);
    sort(ed.begin(), ed.end(), [](const edge &a, const edge &b) -> bool
         { return a.money < b.money; });
    for (int i = 0; i < vexset.size(); i++)
    {
        vexset[i] = i;
        cout << vexset[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < ed.size(); i++)
    {
        for (auto i : vexset)
        {
            cout << i << ' ';
        }
        cout << endl;
        if (vexset[ed[i].end] != vexset[ed[i].start])
        {
            result.push_back(i);
            int temp2 = vexset[ed[i].start];
            for (int j = 0; j < vexset.size(); j++)
            {
                if (vexset[j] == temp2)
                {
                    vexset[j] = vexset[ed[i].end];
                }
            }
        }
    }
    int cnt = 0;
    for (auto &i : result)
    {
        cnt += ed[i].money;
    }
    if (check(vexset))
    {
        cout << cnt << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}