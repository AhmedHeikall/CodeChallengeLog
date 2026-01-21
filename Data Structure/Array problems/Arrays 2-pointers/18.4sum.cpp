// https://leetcode.com/problems/4sum/

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
#include<cassert>
using namespace std;

/*
Why do we sort v before inserting into filter?
vector<int> v { nums[i], nums[j], nums[left], nums[right] };
sort(v.begin(), v.end());

Very important reason 👇

A set considers order when checking uniqueness.

So these two vectors are considered different if not sorted:

{1, 0, -1, 2}
{-1, 0, 1, 2}

Even though they contain the same numbers, the order is different.

Sorting makes a canonical form

After sorting:

{-1, 0, 1, 2}
{-1, 0, 1, 2}


➡ Now the set can detect duplicates correctly


4️⃣ What does filter.insert(v) return?
filter.insert(v)


It returns:

pair<iterator, bool>

The .second part:
filter.insert(v).second

Value	Meaning
true	v was inserted successfully (new element)
false	v already exists (duplicate)
5️⃣ Why do we check .second?
if (filter.insert(v).second)
    ret.push_back(v);

Meaning in plain English:

“Only add this quadruplet to the result if it was NOT already added before.”

*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int> > ret;
		set<vector<int> > filter;

		// Brute force 2 values: 2 pointers the remaining 2 values!
		for (int i = 0; i <= n - 4; i++) {
			for (int j = i + 1; j <= n - 3; ++j) {
				int left = j + 1, right = n - 1;

				while (left < right) {	// 2-pointers
					// New added test case for overflow. 
					// [1000000000,1000000000,1000000000,1000000000]
					// 0
					long long sum = nums[i] + nums[j];
                    sum += nums[left];
                    sum += nums[right] - target;

					if (!sum) {
						vector<int> v { nums[i], nums[j], nums[left], nums[right] };
						sort(v.begin(), v.end());
						if(filter.insert(v).second)
							ret.push_back(v);
						left++, right--;
					} else if (sum > 0)
						right--;	// let's reduce the sum
					else
						left++;		// let's increase the sum
				}
			}
		}
		return ret;
	}
};

int main() {
	vector<int> nums { 0, 0, 0, 0};
	//vector<int> nums { 2,2,2,2,2 };
	Solution s;
	cout<<s.fourSum(nums, 0).size();

	return 0;
}
