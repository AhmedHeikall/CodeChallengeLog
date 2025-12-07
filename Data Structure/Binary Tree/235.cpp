// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
#include <iostream>
#include <cassert>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {
	}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		// if both on left or right subtree, then lca must be in the subtree
		// otherwise this node is lca: x is in a branch and y in another
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);

		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);

		return root;
	}
	//Tip: to find the path between any 2 nodes: you get their lca
	//then path (lca, a) + path(lca, b)
};

int main() {

	return 0;
}

