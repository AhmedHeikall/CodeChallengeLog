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
/*
 * Reverse thinking
 * 	Instead of finding the next greater of an element
 * 	Use an element to find all items it is greater than them
 *
 * We will add each new element in the stack waiting for its next greater
 *
 * Given a new number, iterate on all previous in the stack
 * 	and mark my self as their next great
 * 	but stop once found a number >= me
 * 	why? because I can't be used for more numbers (he is better than me)
 *
 * 	Example: {30, 20, 10, 7, 8, 15}
 * 	Assume stack has now positions for { 30, 20, 10, 7}
 * 	Now we have 8: 8 pops from stack 7 as it is > than it, but stop at 10
 * 	Now we have 15: 15 pops from stack 8, 10 as it is > than it, but stop at 20
 * 	and so on
 *
 * O(n) time! We iterate on numbers ~twice
 */

vector<int> next_greater_idx(vector<int>& v) {
	stack<int> pos;
	for (int i = 0; i < (int) v.size(); ++i) {
		while (!pos.empty() && v[i] > v[pos.top()])
			v[pos.top()] = i, pos.pop();
		pos.push(i);
	}
	// all items in the stack have no next-greater
	while (!pos.empty())
		v[pos.top()] = -1, pos.pop();
	return v;
}

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& v) {
		v = next_greater_idx(v);
		return v;

		for (int i = 0; i < (int) v.size(); ++i) {
			if (v[i] == -1)
				v[i] = 0;
			else
				v[i] -= i; // how many steps
		}
		return v;
	}
};

int main() {
	Solution s;
	vector<int> v { 10 ,5 ,7, 15, 11 };
	//s.dailyTemperatures(v);
	v = next_greater_idx(v);
	for (int i = 0; i < (int) v.size(); ++i)
		cout << v[i] << " ";

	return 0;
}
