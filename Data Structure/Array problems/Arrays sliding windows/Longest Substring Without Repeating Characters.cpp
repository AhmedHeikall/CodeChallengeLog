#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:

	int lengthOfLongestSubstring(string s) { // O(n^2) 
		int result = 0, n = s.size();
		for (int start = 0; start < n; ++start) {
			bool visited[256] { };

			for (int end = start; end < n; ++end) {
				if (visited[s[end]])
					break;
				visited[s[end]] = true;
				result = max(result, end - start + 1); 
			}
		}
		return result;
	}

  int lengthOfLongestSubstring_v2(string s) { // O(n)
		int result = 0;
		unordered_map<char, int> last_visited;

		for (int start = 0, end = 0; end < (int)s.size(); ++end) {
			if(last_visited.count(s[end])) {
				// remove all unrelevant letters before the start of new memory
				int next_start = last_visited[s[end]] + 1;
				for(;start < next_start; start++)
					last_visited.erase(s[start]);		// START makes more sense
			}
			result = max(result, end - start + 1);
			last_visited[s[end]] = end;
		}
		return result;
	}
};

int main() {
}

