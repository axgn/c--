#include <iostream>
constexpr int MAX_SIZE = 1000;

void build_tree(int arr[], int tree[], int node, int left, int right)
{
    if (left == right)
    {
        tree[node] = arr[left];
    }
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(arr, tree, left_node, left, mid);
        build_tree(arr, tree, right_node, mid + 1, right);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(int arr[], int tree[], int node, int left, int right, int idx, int val)
{
    if (left == right)
    {
        arr[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx > mid)
        {
            update_tree(arr, tree, right_node, mid + 1, right, idx, val);
        }
        else
        {
            update_tree(arr, tree, left_node, left, mid, idx, val);
        }
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query_tree(int arr[], int tree[], int node, int left, int right, int L, int R)
{
    std::cout << left << ' ' << right << '\n';
    if (L > right || R < left)
    {
        return 0;
    }
    else if (left >= L && right <= R)
    {
        return tree[node];
    }
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left = query_tree(arr, tree, left_node, left, mid, L, R);
        int sum_right = query_tree(arr, tree, right_node, mid + 1, right, L, R);
        return sum_left + sum_right;
    }
}
int main()
{
    int length = 6;
    int arr[length] = {1, 3, 5, 7, 9, 11};
    int tree[MAX_SIZE] = {0};
    build_tree(arr, tree, 0, 0, length - 1);
    for (int i = 0; i < 15; i++)
    {
        std::cout << "tree[" << i << "] = " << tree[i] << '\n';
    }
    std::cout << '\n';
    update_tree(arr, tree, 0, 0, length - 1, 4, 6);
    for (int i = 0; i < 15; i++)
    {
        std::cout << "tree[" << i << "] = " << tree[i] << '\n';
    }
    std::cout << '\n';
    std::cout << query_tree(arr, tree, 0, 0, length - 1, 2, 5)
    << '\n';
    return 0;
}