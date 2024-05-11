#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <limits>

using namespace std;

struct info
{
    int dis{};
    int cost{};
};

struct edge
{
    int des{};
    shared_ptr<info> pt{};
};

int find_min_pos(vector<int> &min_path, int S, const vector<bool> &is_arrived)
{
    int pos = -1;
    int min = INT_MAX;
    for (int i = 0; i < min_path.size(); i++)
    {
        if (!is_arrived[i] && min_path[i] < min)
        {
            min = min_path[i];
            pos = i;
        }
    }
    return pos;
}

int find_cost(vector<vector<edge>> ALGraph, int s, int d)
{
    for (int i = 0; i < ALGraph[s].size(); i++)
    {
        if (ALGraph[s][i].des == d)
        {
            return ALGraph[s][i].pt->cost;
        }
    }
    return 0;
}

void dijkstar(vector<int> &min_path, vector<int> &before,
              const vector<vector<edge>> &ALGraph, int S, vector<int> &min_cost)
{
    min_path[S] = 0;
    min_cost[S] = 0;
    vector<bool> is_arrived(ALGraph.size(), false);
    int temp = S;
    for (int j = 0; j < ALGraph.size(); j++)
    {
        for (int i = 0; i < ALGraph[temp].size(); i++)
        {
            edge next_e = ALGraph[temp][i];
            if (!is_arrived[next_e.des])
            {
                if (min_path[temp] + next_e.pt->dis < min_path[next_e.des])
                {
                    min_path[next_e.des] = min_path[temp] + next_e.pt->dis;
                    min_cost[next_e.des] = min_cost[temp] + next_e.pt->cost;
                    before[next_e.des] = temp;
                }
                else if (min_path[temp] + next_e.pt->dis == min_path[next_e.des])
                {
                    if (min_cost[temp] + next_e.pt->cost < min_cost[next_e.des])
                    {
                        min_path[next_e.des] = min_path[temp] + next_e.pt->dis;
                        min_cost[next_e.des] = min_cost[temp] + next_e.pt->cost;
                        before[next_e.des] = temp;
                    }
                }
            }
        }
        int pos = find_min_pos(min_path, S, is_arrived);
        is_arrived[pos] = true;
        temp = pos;
    }
}

int main()
{
    int N, M, S, D; // N城市的个数,M是高速公路的条,S是出发地,D是目的地
    cin >> N >> M >> S >> D;
    vector<vector<edge>> ALGraph(N);
    vector<int> min_path(N, INT_MAX);
    vector<int> min_cost(N, INT_MAX);
    vector<int> before(N, -1);
    for (int i = 0; i < M; i++)
    {
        int start, end, cost, dis;
        cin >> start >> end >> dis >> cost;
        shared_ptr<info> tmp = make_shared<info>(info{dis, cost});
        ALGraph[start].push_back({end, tmp});
        ALGraph[end].push_back({start, tmp});
    }
    dijkstar(min_path, before, ALGraph, S, min_cost);
    int cost = 0;
    int temp = D;
    while (temp != S)
    {
        int temp1 = temp;
        temp = before[temp];
        cost += find_cost(ALGraph, temp, temp1);
    }
    cout << min_path[D] << ' ' << cost;
    return 0;
}