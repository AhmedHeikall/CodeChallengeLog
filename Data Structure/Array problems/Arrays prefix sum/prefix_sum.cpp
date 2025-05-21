#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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

int main() {
	vector<int> v { 5, 2, 7, 1, 0, 3, 2 };
	prefix_sum(v);

	cout << range_sum(0, 6, v) << "\n";
	cout << range_sum(1, 6, v) << "\n";

}

