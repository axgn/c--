#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution1
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp = nums;
        do
        {
            next_permutation(temp.begin(), temp.end());
            res.emplace_back(temp);
        } while (nums != temp);
        return res;
    }
};


class Solution2
{
private:
    vector<vector<int>> res;
    set<vector<int>> temp;
    void dfs(vector<int> &nums, int index, int len)
    {
        if (index == len)
        {
            temp.insert(nums);
            return;
        }
        for (int i = index; i < len; i++)
        {
            swap(nums[i], nums[index]);
            dfs(nums, index + 1, len);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        dfs(nums, 0, nums.size());
        for (auto i : temp)
        {
            res.emplace_back(i);
        }
        return res;
    }
};

class Solution
{
private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, int index, int len)
    {
        unordered_set<int> temp;
        if (index == len)
        {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < len; i++)
        {
            if (!temp.count(nums[i]))
            {
                swap(nums[i], nums[index]);
                dfs(nums, index + 1, len);
                swap(nums[i], nums[index]);
                temp.insert(nums[i]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        dfs(nums, 0, nums.size());
        return res;
    }
};

int main()
{
    vector<int> a = {1, 1, 3};
    vector<int> b = {1, 2, 3};
    a.swap(a);
    Solution1 s;
    Solution s2;
    vector<vector<int>> res2 = s2.permuteUnique(a);
    for (auto &i : res2)
    {
        for (auto &j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}