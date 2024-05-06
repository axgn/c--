#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                        right(right) {}
};
TreeNode *build(string &s_pre, string &s_in, int in_left, int in_right,
                int pre_left, int pre_right, unordered_map<char, int> pos)
{
    TreeNode *root = new TreeNode(s_pre[pre_left]);
    int k = pos[s_pre[pre_left]];
    if (k > in_left)
    {
        root->left = build(s_pre, s_in, in_left, k - 1, pre_left + 1, pre_left + k - in_left, pos);
    }
    if (k < in_right)
    {
        root->right = build(s_pre, s_in, k + 1, in_right, pre_left + k - in_left + 1, pre_right, pos);
    }
    return root;
}

void inord(TreeNode *root)
{
    if (root)
    {
        inord(root->left);
        cout << root->val;
        inord(root->right);
    }
}

int depth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    return max(depth(root->left), depth(root->right)) + 1;
}

int main()
{
    int n;
    cin >> n;
    string s_in;
    string s_pre;
    cin >> s_pre >> s_in;
    unordered_map<char, int> pos;
    for (int i = 0; i < s_in.length(); i++)
    {
        pos[s_in[i]] = i;
    }
    TreeNode *root = build(s_pre, s_in, 0, n - 1, 0, n - 1, pos);
    cout << depth(root);
    return 0;
}