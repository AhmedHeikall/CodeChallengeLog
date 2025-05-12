#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:

	// long long to avoid over flow
	bool possible(int n, long long rows) {
		long sum = (rows * (rows + 1)) / 2;
		return n >= sum;
	}
	int arrangeCoins(int n) {
		int left = 0, right = n, answer = 0;
		// find last occurrence
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (possible(n, mid))
				left = mid + 1, answer = mid;
			else
				right = mid - 1;
		}
		return answer;
	}

};

int main() {
	Solution s;
	s.arrangeCoins(8);

	return 0;
}

