#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
#include<cassert>
using namespace std;

class Solution {
public:

	int maxArea(vector<int>& nums) {
		int area = 0;
		int left = 0, right = (int) nums.size() - 1;
		while (left < right) {
			area = max(area, (min(nums[left], nums[right]) * (right - left)));

			if (nums[left] < nums[right])
				left = left + 1;
			else
				right = right - 1;
		}
		return area;
	}

};

int main() {
	vector<int> nums { 10, 11, 21, 0, 0, 0, 0, 0, 0, 20 };
	Solution s;
	cout << s.maxArea(nums);

	return 0;
}
