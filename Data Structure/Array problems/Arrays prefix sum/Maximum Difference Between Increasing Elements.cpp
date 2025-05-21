#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int maxDifference_v1(vector<int>& nums) {	// O(n^2)
	int ans = INT_MIN;
	for (int i = 0; i < (int) nums.size(); ++i)
		for (int j = i + 1; j < (int) nums.size(); ++j)
			if (nums[i] < nums[j])
				ans = max(ans, nums[j] - nums[i]);
				
	if(ans == INT_MIN)
		return -1;
	return ans;
}

  int maximumDifference_v2(vector<int>& nums) { // O(n)
        int ans = INT_MIN;
        int mx_so_far = nums.back();
        for (int i = (int) nums.size() - 2; i >= 0; --i) {
            if (nums[i] < mx_so_far)
                ans = max(ans, mx_so_far - nums[i]);
            mx_so_far = max(mx_so_far, nums[i]);
        }
        if(ans == INT_MIN)
            return -1;
        return ans;
    }


int main() {
	vector<int> nums { 1000, 2, 3, 10, 6, 4, 8, 1 };
	cout << maxDifference_v1(nums) << "\n";

	nums = {7, 9, 5, 6, 3, 2};
	cout << maxDifference_v1(nums) << "\n";

	nums = {2, 5, 15, 6, 4};
	cout << maxDifference_v1(nums) << "\n";

	return 0;
}
