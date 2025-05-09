#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

/*
 * Assume we sorted the array. Can we rearrange its elements to satisfy wiggleSort?
 * 1, 2, 3, 4, 5, 6, 7, 8
 *
 * nums[0] is the smallest in the array and satisfy the target
 *
 * The next one? All the next numbers are all valid choices
 * 	Boundary thinking? Maybe 2 (the next) or 8 (the last)
 *
 * What about the largest? This is 8
 * So now 1 8
 * The remaining numbers is what we call a sub-problem
 * 		Sub-problem: [2, 3, 4, 5, 6, 7]
 * We want them to be waggle sort
 * So we take the first (2) with the last (7)
 * and so on
 * Ending with: 1, 8, 2, 7, 3, 6, 5, 4
 *
 * We have to create O(n) memory to save the output
 */

// O(nlogn) time and O(n) space
	void wiggleSort(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		// From: 1, 2, 3, 4, 5, 6, 7, 8
		// To  : 1, 8, 2, 7, 3, 6, 5, 4

		vector<int> ans;	// O(n) extra memory

		int left = 0, right = nums.size()-1;
		while (left <= right) {
			ans.push_back(nums[left]);
			if(left != right)	// don't add same position twice
				ans.push_back(nums[right]);
			left += 1;
			right -= 1;
		}
		nums =  ans;
	}