#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q1;
        vector<vector<int>> result;
        q1.push(root);
        while (!q1.empty())
        {
            result.push_back({});
            for (int i = 0; i < q1.size(); i++)
            {
                TreeNode *temp = q1.front();
                q1.pop();
                if (temp)
                {
                    result.back().push_back(temp->val);
                    q1.push(temp->left);
                    q1.push(temp->right);
                }
            }
        }
        return result;
    }
};