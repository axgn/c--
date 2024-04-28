#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return;
        }
        bool flag = true;
        cout << "ssdfaf";
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                for (int j = nums.size() - 1; j >= i; j--)
                {
                    if (nums[j] > nums[i - 1])
                    {
                        swap(nums[j], nums[i - 1]);
                        reverse(nums.begin() + i, nums.end());
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                    break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < nums.size() / 2; i++)
            {
                swap(nums[i], nums[nums.size() - i - 1]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 3, 1};
    s.nextPermutation(v);
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    next_permutation(v.begin(), v.end());
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    return 0;
}