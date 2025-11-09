// https://leetcode.com/problems/is-subsequence/
#include <iostream>
using namespace std;

class Solution {
public:
 bool isSubsequence(string s, string t) {
    int ptr_1 = 0, ptr_2 = 0, matched_cnt = 0;
  
    while (ptr_1 < (int) s.size() && ptr_2 < (int) t.size()) {
      if (s[ptr_1] == t[ptr_2]) {
        matched_cnt++;
        ptr_1++;
        ptr_2++;
      } else {
        ptr_2++;
      }
    }
    return (matched_cnt == (int) s.size());
    }
};