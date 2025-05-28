// https://leetcode.com/problems/max-consecutive-ones-iii/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

void f1() {
	string s = "abcd";
	for (int start = 0; start < (int) s.size(); ++start)
		for (int end = start; end < (int) s.size(); ++end)
			cout << s.substr(start, end - start + 1) << "\n";
}

void f2() {

	string s = "abcd";
	for (int sz = 1; sz <= (int) s.size(); ++sz)
		for (int start = 0; start + sz <= (int) s.size(); ++start)
			cout << s.substr(start, sz) << "\n";

}

void f1_v() {

	string s = "abcd";
	for (int start = 0; start < (int) s.size(); ++start) {
		string substr;	// keep EXAPNDING the window content
		for (int end = start; end < (int) s.size(); ++end) {
			substr += s[end];
			cout << substr << "\n";
		}
	}

}

int longest_at_most_k_v1(vector<int> &nums, int k) {	// O(n^3)
	int len = 0;

	for (int start = 0; start < (int) nums.size(); ++start) {
		for (int end = start; end < (int) nums.size(); ++end) {
			int zeros = 0;
			for (int r = start; r <= end; ++r)
				zeros += nums[r] == 0;

			if (zeros <= k)
				len = max(len, end - start + 1);
		}
	}
	return len;
}

int longest_at_most_k_v2(vector<int> &nums, int k) {	// O(n^2)
	int len = 0;

	for (int start = 0; start < (int) nums.size(); ++start) {
		for (int end = start, zeros = 0; end < (int) nums.size(); ++end) {
			zeros += nums[end] == 0;

			if (zeros <= k)
				len = max(len, end - start + 1);
			else
				break;
		}
	}
	return len;
}

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {	// O(n)
		int len = 0;
		for (int start = 0, end = 0, zeros = 0; end < (int) nums.size(); ++end) {
			if (nums[end] == 0) {	// shift right
				zeros++;

				while (zeros > k) { // while invalid: shift left
					zeros -= nums[start] == 0;
					start = start + 1;
				}
			}
			len = max(len, end - start + 1);
		}
		return len;
	}
};

int main() {
	vector<int> v { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
	cout << longest_at_most_k_v2(v, 0) << "\n";
	cout << longest_at_most_k_v2(v, 1) << "\n";
	cout << longest_at_most_k_v2(v, 2) << "\n";
	cout << longest_at_most_k_v2(v, 3) << "\n";

}

