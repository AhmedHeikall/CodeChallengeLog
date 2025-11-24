#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :
			val(0), left(nullptr), right(nullptr) {
	}
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
			val(x), left(left), right(right) {
	}
};

class Solution {
	int max_diameter_so_far = 0;

	int height(TreeNode* root) {
		if (!root)
			return 0;

		int left_height = height(root->left);
		int right_height = height(root->right);
		max_diameter_so_far = max(max_diameter_so_far, left_height + right_height);

		return 1 + max(left_height, right_height);	// my height
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		height(root);
		return max_diameter_so_far;
	}
};
