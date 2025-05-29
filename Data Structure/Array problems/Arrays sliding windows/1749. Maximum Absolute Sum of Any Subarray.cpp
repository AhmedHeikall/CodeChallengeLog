// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

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
			max_sum_end_i = max(0, max_sum_end_i + nums[i]);
			max_so_far = max(max_so_far, max_sum_end_i);
		}
		return max_so_far;
	}

	int minSubArray(vector<int>& nums) {
		int min_sum_end_i = 0;
		int min_so_far = INT_MAX;

		for (int i = 0; i < (int) nums.size(); i++) {
			min_sum_end_i = min(0, min_sum_end_i + nums[i]);
			min_so_far = min(min_so_far, min_sum_end_i);
		}
		return min_so_far;
	}

    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(maxSubArray(nums)), abs(minSubArray(nums)));
    }
};


int main() {
	vector<int> nums {1,-3,2,3,-4};
	Solution s;
	cout << s.maxSubArray(nums);

	return 0;
}
