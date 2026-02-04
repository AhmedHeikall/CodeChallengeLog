// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		int n = nums.size();
		sort(nums.begin(), nums.end()); // MUST
		vector<vector<int>> ret;

		// Brute force a value: 2 pointers the remaining 2 values!
		for (int i = 0; i <= n - 3; i++)
		{
			if ((i > 0) && (nums[i] == nums[i - 1]))
				continue; // previous element tried already (this pair)

			int left = i + 1, right = n - 1;

			while (left < right)
			{ // 2-pointers
				int sum = nums[i] + nums[left] + nums[right];

				if (!sum)
				{
					ret.push_back({nums[i], nums[left], nums[right]});
					left++;
					while (left < right && nums[left] == nums[left - 1])
						left++;
					right--;
					while (left < right && nums[right] == nums[right + 1])
						right--; // We can actually remove this loop
				}
				else if (sum > 0)
					right--; // let's reduce the sum
				else
					left++; // let's increase the sum
			}
		}
		return ret;
	}
};

int main()
{
	// vector<int> nums { -1, 0, 1, 2, -1, -4 };
	vector<int> nums{2, 2, 3, 3, -5};
	Solution s;
	cout << s.threeSum(nums).size();

	return 0;
}
