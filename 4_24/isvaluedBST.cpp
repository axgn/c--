#include <iostream>
#include <vector>

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
    bool isvaltree(TreeNode *root, int left, int right)
    {
        if (root)
        {
            if (root->val > left && root->val < right)
            {
                return isvaltree(root->left, left, root->val) && isvaltree(root->right, root->val, right);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        return isvaltree(root, INT_MIN, INT_MAX);
    }
};

class Solution2
{
private:
    vector<int> v;
    int max;
    int min;
    void inordedTree(TreeNode *root)
    {
        if (root)
        {
            inordedTree(root->left);
            v.push_back(root->val);
            inordedTree(root->right);
        }
    }
    void inordedTree2(TreeNode *root)
    {
        if (root)
        {
            if (root->val == min)
            {
                root->val = max;
            }
            if (root->val == max)
            {
                root->val = min;
            }
            inordedTree2(root->left);
            inordedTree2(root->right);
        }
    }

public:
    void recoverTree(TreeNode *root)
    {
        inordedTree(root);
        vector<int> cnt;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                cnt.push_back(i);
            }
        }
        if (cnt.size() == 1)
        {
            max = v[cnt[0]];
            min = v[cnt[0] + 1];
        }
        else
        {
            max = v[cnt[0]];
            min = v[cnt[1] + 1];
        }
        inordedTree2(root);
    }
};