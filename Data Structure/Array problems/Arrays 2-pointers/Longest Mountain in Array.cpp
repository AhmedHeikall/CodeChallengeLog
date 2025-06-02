#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), idx = 0, longest = 0, start, end;

        while (idx < n) {
            start = idx;
            while(idx + 1 < n && arr[idx] < arr[idx+1])
              ++idx;     // walk up
            if(start == idx) {
                ++idx;
                continue;
            }  
            end = idx;
            while(idx + 1 < n && arr[idx] > arr[idx+1])
              ++idx;
            if (end == idx) {
                ++idx;
                continue;
            }  
            longest = max(longest, idx - start + 1);
        }
        return longest;
    }
};