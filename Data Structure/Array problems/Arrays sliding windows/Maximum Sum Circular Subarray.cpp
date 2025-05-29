// https://leetcode.com/problems/maximum-sum-circular-subarray/
// https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:

	int maxSubArray(vector<int>& nums) {
		int max_sum_end_i = 0;
		int max_so_far = INT_MIN;

		for (int i = 0; i < (int) nums.size(); i++) {
			max_sum_end_i = max(nums[i], max_sum_end_i + nums[i]);
			max_so_far = max(max_so_far, max_sum_end_i);
		}
		return max_so_far;
	}

	int minSubArray(vector<int>& nums) {
		int min_sum_end_i = 0;
		int min_so_far = INT_MAX;

		for (int i = 0; i < (int) nums.size(); i++) {
			min_sum_end_i = min(nums[i], min_sum_end_i + nums[i]);
			min_so_far = min(min_so_far, min_sum_end_i);
		}
		return min_so_far;
	}

	int sum(vector<int>& nums) {
		int sum = 0;
 
		for (int i = 0; i < (int) nums.size(); i++)
			sum += nums[i];

		return sum;
	}

	int maxSubarraySumCircular(vector<int>& nums) {
		int mx = maxSubArray(nums);
		int mn = minSubArray(nums);
		int sm = sum(nums);

		if(sm == mn)	// whole window is -ve: be careul
			return mx;
		return max(mx, sm - mn);
	}
};

int main() {
	vector<int> nums { -15, 10, -20 };
	Solution s;
	cout << s.maxSubArray(nums) << " " << s.minSubArray(nums);

	return 0;
}
