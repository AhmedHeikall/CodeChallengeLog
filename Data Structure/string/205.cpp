// https://leetcode.com/problems/isomorphic-strings/

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
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> mp1, mp2;

		for (int i = 0; i < (int)s.size(); i++) {
			char ch1 = s[i], ch2 = t[i];

			if(mp1.count(ch1) && mp1[ch1] != ch2)
				return false;

			if(mp2.count(ch2) && mp2[ch2] != ch1)
				return false;

			mp1[ch1] = ch2, mp2[ch2] = ch1;
		}
		return true;
	}
};

int main() {
	vector<int> nums { 10, 11, 21, 0, 0, 0, 0, 0, 0, 20 };
	Solution s;
	cout << s.isIsomorphic("ACABAA", "XCXYXX");

	return 0;
}
