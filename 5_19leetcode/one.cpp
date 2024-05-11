#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

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

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        unordered_map<TreeNode *, int> map1;
        queue<TreeNode *> q1;
        vector<vector<int>> res;
        q1.push(root);
        map1[root] = 1;
        res.push_back({root->val});
        TreeNode *temp;
        while (!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            if (temp->left)
            {
                q1.push(temp->left);
                map1[temp->left] = map1[temp] + 1;
                if (res.size() < map1[temp->left])
                {
                    res.push_back({});
                }
                res[map1[temp->left] - 1].push_back(temp->left->val);
            }
            if (temp->right)
            {
                q1.push(temp->right);
                map1[temp->right] = map1[temp] + 1;
                if (res.size() < map1[temp->right])
                {
                    res.push_back({});
                }
                res[map1[temp->right] - 1].push_back(temp->right->val);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};