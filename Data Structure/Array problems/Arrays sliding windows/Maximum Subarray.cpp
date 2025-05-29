#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
	/*
	 * Let's get the maximum window ending at each position
	 *
	 * How to get the max for current window
	 * Let's say we have prefix P
	 * Now we want to cancel a previous window
	 * Simply, the minimum prefix among all prefixes is the best
	 *
	 * For each step: subtract current prefix from the min prefix so far
	 * Consider: whole prefix can be a solution
	 */

	int maxSubArray(vector<int>& nums) {
		int prefix_sum = 0;
		int prefix_sum_min_so_far = INT_MAX;
		int max_so_far = INT_MIN;

		for (int i = 0; i < (int) nums.size(); i++) {
			prefix_sum += nums[i];
			max_so_far = max(max_so_far, prefix_sum);	// whole window

			if (i)
				max_so_far = max(max_so_far, prefix_sum - prefix_sum_min_so_far);

			prefix_sum_min_so_far = min(prefix_sum_min_so_far, prefix_sum);
		}
		return max_so_far;
	}
};

int main() {
	vector<int> nums { 5, 4, -1, 7, 8 };
	Solution s;
	cout << s.maxSubArray(nums);

	return 0;
}
