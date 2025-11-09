#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:


	bool validPalindrome(string s) {
		return isValidPalindrome(s, 0, (int)s.size()-1, 1);
	}

	bool isValidPalindrome(const string &str, int left, int right, int delete_limit) {
		if (left >= right)
			return true;

		if (str[left] == str[right])	// Match. Greedily we DON'T TRY deleting
			return isValidPalindrome(str, left + 1, right - 1, delete_limit);

		if (delete_limit)
			return isValidPalindrome(str, left + 1, right, delete_limit - 1) ||
				   isValidPalindrome(str, left, right - 1, delete_limit - 1);
		return false;
	}
};

int main() {

	return 0;
}
