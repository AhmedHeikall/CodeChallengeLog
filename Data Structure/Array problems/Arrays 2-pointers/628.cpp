

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int b = nums[0] * nums[1] * nums[n - 1];
        return max(a, b);
    }
};

int main()
{
    Solution s;
    vector<int> nums{-20, -10, -7, -6, -5, 2, 3, 4, 5};
    cout << s.maximumProduct(nums);
}
