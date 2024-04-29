#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

bool isSymmetric(TreeNode *T)
{
    deque<TreeNode *> temp;
    temp.push_back(T);
    TreeNode *temp1 = T;
    while (!temp.empty())
    {
        T = temp.front();
        temp.pop_front();
        if (T)
        {
            temp.push_back(T->left);
            temp.push_back(T->right);
            if (T == temp1->right)
            {
                temp1 = T;
                auto iter = temp.begin();
                auto iter2 = temp.end() - 1;
                while (iter <= iter2)
                {
                    if (*iter != *iter2)
                    {
                        return false;
                    }
                    iter++;
                    iter2--;
                }
            }
        }
    }
    return true;
}

int main()
{

    return 0;
}