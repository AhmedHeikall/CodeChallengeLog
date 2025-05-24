#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<int> productArray(const vector<int> &nums) {
  const int sz = nums.size();

  vector<int> prefix(sz, 1);
  vector<int> suffix(sz, 1);
  vector<int> answer(sz);
  
  // Fill prefix array
  for (int i = 1; i < sz; ++i)
    prefix[i] = prefix[i - 1] * nums[i - 1];

  // Fill suffix array
  for (int i = sz - 2; i >= 0; --i) 
    suffix[i] = suffix[i + 1] * nums[i + 1];
  
  // calculate the result
  for (int i = 0; i < sz; ++i)
    answer[i] = prefix[i] * suffix[i];
  
  return answer;
}

vector<int> productArray_v2(const vector<int> &nums){
  int sz = nums.size();
  vector<int> answer(sz);
  
  answer[0] = 1;
  // calculate prefix product
  for (int i = 1; i < sz; ++i)
    answer[i] = answer[i - 1] * nums[i - 1];

  int prevSuffix = 1;
  // calculate the suffixProduct and update answer
  for (int i = sz - 2; i >= 0; --i){
    prevSuffix *= nums[i + 1];
    answer[i] *= prevSuffix;
  }  
  return answer;
}
};



int main() {
  Solution s;
  vector<int> result1 = s.productArray({1,2,3,4}) ;
  vector<int> result2 = s.productArray_v2({1,2,3,4}) ;

  for (int x : result1)
    cout << x << " ";
  
  cout << "\n";
  for (int x : result2)
    cout << x << " ";
  return 0;
}
