// https://leetcode.com/problems/move-zeroes/solution/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int non_zeros_cnt = 0;

        for (int i = 0; i < (int)nums.size(); ++i)
            if (nums[i] != 0)
                swap(nums[non_zeros_cnt++], nums[i]);
    }
};
