/*
given an integer array nums and k,  k -> number of consuctive elements
return the maximum consuctive elements inside the array
*/  

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


void prefix_sum(vector<int> &nums) {
	for (int i = 1; i < (int) nums.size(); ++i)
		nums[i] += nums[i - 1];	// dp[i] = A[i] + d[i-1]
}

int range_sum(int s, int e, vector<int> &prefix) {
	if (s == 0)
		return prefix[e];
	return prefix[e] - prefix[s - 1];
}


// brute force solution O(n^2)
int maxConsuctive_v1(vector<int> &nums, int k) {
  int best = INT_MIN;

  for (int start = 0; start < (int) nums.size() -k + 1; ++start) {
    int sum = 0;
    for (int s = 0; s < k; ++s) {
        sum += nums[s + start];
    }
    best = max(best, sum);
  }
  return best;
}

// prefix solution O(n)
int maxConsectiveSum_k_v2(vector<int>& nums, int k) {
	prefix_sum(nums);

	int best = INT_MIN;
	for (int start = 0; start < (int) nums.size() - k + 1; ++start)
		best = max(best, range_sum(start, start + k - 1, nums));

	return best;
}

int maxConsectiveSum_k_v3(vector<int>& nums, int k) {
	int window_sum = 0;
	// building first k elements
	for (int end = 0; end < k; ++end)
		window_sum += nums[end];
	int best = window_sum;

	for (int end = k; end < (int) nums.size(); ++end) {
		window_sum += nums[end] - nums[end - k];
		best = max(best, window_sum);
	}
	return best;
}

int main() {
	vector<int> v { 1, 3, 6, 4, 5, 3, 8, 2 };
	//

	cout << maxConsectiveSum_k_v3(v, 5);

}