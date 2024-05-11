#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;

struct point
{
    double x = 0;
    double y = 0;
};

bool test_success(vector<bool> &arr, vector<bool> &succ)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] && succ[i])
        {
            return true;
        }
    }
    return false;
}

double caculate_dis(const point &a, const point &b)
{
    return hypotf(a.x - b.x, a.y - b.y);
}

void create_arr(vector<bool> &can_arr, const vector<point> &fishs, const point &island_p, const int D)
{
    for (int i = 0; i < fishs.size(); i++)
    {
        if (caculate_dis(island_p, fishs[i]) <= D + 7.5)
        {
            can_arr[i] = true;
        }
        else
        {
            can_arr[i] = false;
        }
    }
}

void create_succ(vector<bool> &success, const vector<point> &fishs, const double D)
{
    for (int i = 0; i < fishs.size(); i++)
    {
        if (fishs[i].x >= 50 - D || fishs[i].x <= -50 + D || fishs[i].y >= 50 - D || fishs[i].y <= -50 + D)
        {
            success[i] = true;
        }
        else
        {
            success[i] = false;
        }
    }
}

void extend_arr(vector<bool> &can_arr, const vector<point> &fishs, const double D)
{
    queue<int> temp;
    vector<bool> flag(fishs.size(), false);
    for (int i = 0; i < fishs.size(); i++)
    {
        if (can_arr[i] && !flag[i])
        {
            temp.push(i);
            flag[i] = true;
        }
        while (!temp.empty())
        {
            int temp1 = temp.front();
            temp.pop();
            for (int i = 0; i < fishs.size(); i++)
            {
                if (!can_arr[i] && !flag[i] && caculate_dis(fishs[i], fishs[temp1]) < D)
                {
                    temp.push(i);
                    flag[i] = true;
                    can_arr[i] = true;
                }
            }
        }
    }
}

int main()
{
    int N, D;
    cin >> N >> D;
    vector<point> fishs;
    point island_p;
    vector<bool> can_arr(N, false);
    vector<bool> success(N, false);
    for (int i = 0; i < N; i++)
    {
        fishs.push_back({0, 0});
        cin >> fishs.back().x >> fishs.back().y;
    }
    create_arr(can_arr, fishs, island_p, D);
    create_succ(success, fishs, D);
    extend_arr(can_arr, fishs, D);
    for (auto i : can_arr)
    {
        cout << boolalpha << i << ' ';
    }
    cout << '\n';
    for (auto i : success)
    {
        cout << boolalpha << i << ' ';
    }
    cout << '\n';
    if (test_success(can_arr, success))
    {
        cout << "yes" << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }
    return 0;
}