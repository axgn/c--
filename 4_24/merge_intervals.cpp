#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (intervals[i][1] > intervals[i + 1][0])
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        res.push_back(intervals[intervals.size() - 1]);
        return res;
    }
};

int main()
{
    vector<vector<int>> v = {{3, 4}, {1, 6}, {7, 9}, {8, 10}, {4, 5}};
    Solution s;
    vector<vector<int>> res = s.merge(v);
    auto fun = [&](const vector<int> temp)
    { for_each(temp.begin(), temp.end(), [&](const int a)
               { cout << a << ' '; });
               cout << '\n'; };
    for_each(v.begin(), v.end(), fun);
    for_each(res.begin(), res.end(), fun);
}
#include <iostream>
#include <string>

using namespace std;

int i = 0;

struct Bitree
{
    char data = 0;
    Bitree *lchild = nullptr;
    Bitree *rchild = nullptr;
};

void creatBi(Bitree *Troot, string s)
{
    if (Troot != nullptr)
        Troot->data = s[i];
    if (s[++i] != '#')
    {
        Troot->lchild = new Bitree;
        creatBi(Troot->lchild, s);
    }
    if (s[++i] != '#')
    {
        Troot->rchild = new Bitree;
        creatBi(Troot->rchild, s);
    }
}

void inordedtravel(Bitree *T)
{
    if (T)
    {
        inordedtravel(T->lchild);
        cout << T->data << ' ';
        inordedtravel(T->rchild);
    }
}

int main()
{
    string s = "abc##de#g##f###";
    Bitree *tree = new Bitree;
    creatBi(tree, s);
    inordedtravel(tree);
    return 0;
}