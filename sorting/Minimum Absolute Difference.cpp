#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &nums) {
  int min_diff = INT_MAX;
  // sort array
  sort(nums.begin(), nums.end());

  // find minimum absolute difference
  for (int i = 1; i < (int) nums.size(); i++) {
    min_diff = min(nums[i] - nums[i-1], min_diff);
  }

  //find all consuctive values with min diff
  vector<vector<int>> res;
  for (int i = 1; i < (int) nums.size(); i++) {
    if (nums[i] - nums[i-1] == min_diff)
       res.push_back({nums[i-1], nums[i]});
  }
  return res;
}