// Relevant question: https://leetcode.com/problems/balance-a-binary-search-tree/description/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode* left { };
	TreeNode* right { };
	TreeNode(int val) : val(val) { }
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return sortedArrayToBST(nums, 0, (int) nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& values, int start, int end) {
    	if (start > end)
    		return nullptr;

    	// The best root for N sorted numbers is their middle number
    	// as N/2 numbers before and after. Keep applying recursively
    	int mid = (start + end) / 2;
    	TreeNode *root = new TreeNode(values[mid]);
    	root->left = sortedArrayToBST(values, start, mid - 1);
    	root->right = sortedArrayToBST(values, mid + 1, end);

    	return root;
    }
};


int main() {

	return 0;
}

