#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int binary_search(vector<int> &nums, int val) {
	int start = 0, end = (int) nums.size() - 1;	// (int)

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (nums[mid] == val)
			return mid;
		if (nums[mid] < val)
			start = mid + 1;
		else if (nums[mid] > val)
			end = mid - 1;
	}
	return -1;
}

int main() {

	return 0;
}

