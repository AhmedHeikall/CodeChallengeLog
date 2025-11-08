// https://leetcode.com/problems/valid-anagram

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

	bool isAnagram(string s, string t) {
		unordered_map<char, int> freq1, freq2;

		for (int i = 0; i < (int) s.size(); ++i)
			freq1[s[i]] = freq1[s[i]] + 1;

		for (int i = 0; i < (int) t.size(); ++i)
			freq2[t[i]] = freq2[t[i]] + 1;

		if (freq1.size() != freq2.size())
			return false;	// not same set of letters

		// Check same frequency per letter
		for (const pair<char, int>& x : freq1) {
			char ch = x.first;
			int freq = x.second;

			if (freq2[ch] != freq)
				return false;
		}

		return true;
	}
};

int main() {
	vector<int> nums { 10, 11, 21, 0, 0, 0, 0, 0, 0, 20 };
	Solution s;
	cout << s.isAnagram("ACABAA", "XCXYXX");

	return 0;
}
