#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (temp < nums[i])
            {
                break;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                int temp1 = temp - nums[j];
                if (temp1 < nums[j])
                {
                    break;
                }
                int m = j + 1, n = nums.size() - 1;
                while (m < n)
                {
                    if (temp1 < nums[m] + nums[n])
                    {
                        n--;
                    }
                    else if (temp1 > nums[m] + nums[n])
                    {
                        m++;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 0, -1, 0, -2, 2};
    s.fourSum(v, 0);
    return 0;
}