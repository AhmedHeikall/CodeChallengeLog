#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// the valid triangle must be (the submission of 2 sides must be greater than other.)
// sorting make 1 check

int largestPerimeter(vector<int> &nums) {
  // sort from largest to smallest
  sort(nums.rbegin(), nums.rend());

  // one check is enough as they are sorted
  for (int i = 1; i < (int) nums.size(); i++) {
    if (nums[i] < nums[i+1] + nums[i+2]) 
      return nums[i] + nums[i+1] + nums[i+2];
  }
  return 0;
}