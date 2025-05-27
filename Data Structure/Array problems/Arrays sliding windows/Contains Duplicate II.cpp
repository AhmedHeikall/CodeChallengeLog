// https://leetcode.com/problems/contains-duplicate-ii/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> st;

		for (int i = 0; i < (int) nums.size(); i++) {
			if (st.count(nums[i]))
				return true;

			st.insert(nums[i]);

			if (st.size() > k) // fixed window
				st.erase(nums[i - k]);
		}
		return false;
	}
};

int main() {
	vector<int> nums { 1, 2, 3, 1 };
	Solution s;
	cout << s.containsNearbyDuplicate(nums, 3);

	return 0;
}
