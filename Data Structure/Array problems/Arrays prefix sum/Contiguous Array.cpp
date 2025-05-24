#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int> prefix_table;
		prefix_table[0] = -1;	// prefix 0 always there
		int res = 0, prefix_sum = 0;

		for (int i = 0; i < (int) nums.size(); i++) {
			if(nums[i])
				++prefix_sum;
			else
				--prefix_sum;

			if (prefix_table.count(prefix_sum))
				res = max(res, i - prefix_table[prefix_sum]);
			else	// keep earliest only to maximize
				prefix_table[prefix_sum] = i;
		}

		return res;
	}
};

int main() {
	vector<int> nums { 0, 1, 0, 1};
	Solution s;
	cout << s.findMaxLength(nums);

	return 0;
}
