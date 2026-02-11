// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
	// harder way. I build the sequence part by part.
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> seq_len;

		for (int i = 0; i < (int) nums.size(); ++i)
			seq_len[nums[i]] = 0;

		int ans = 0;
		for (int i = 0; i < (int) nums.size(); ++i) {
			if (seq_len[nums[i]])
				continue;

			int len = 0, val = nums[i];
			while (seq_len.count(val)) {

				if (seq_len[val]) {
					len += seq_len[val];	// we found sequence already from that number. Use its subanswer
					break;
				}
				seq_len[val++] = 1, ++len;
			}
			seq_len[nums[i]] = len;
			ans = max(ans, len);
		}
		return ans;
	}
};

int main() {
	vector<int> nums {100,4,200,1,3,2 };
	Solution s;
	cout << s.longestConsecutive(nums);

	return 0;
}
