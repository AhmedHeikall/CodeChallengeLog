// https://leetcode.com/problems/next-greater-element-ii/
#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<climits>
#include<algorithm>
#include<cassert>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& v) {
		int n = v.size();
		vector<int> res(n, -1);
		stack<int> pos;

		for (int i = 0; i < 2 * n; ++i) {
			while (!pos.empty() && v[i%n] > v[pos.top()])
				res[pos.top()] = v[i % n], pos.pop();

			if (i < n)
				pos.push(i);
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<int> v { 1, 2, 1 };
	v = s.nextGreaterElements(v);

	for (int i = 0; i < (int) v.size(); ++i)
		cout << v[i] << " ";

	return 0;
}
