// https://leetcode.com/problems/symmetric-tree

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode {		// don't copy for leetcode
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {
	}
};

struct BinaryTree {
	TreeNode *root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) {
	}
	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode *current = this->root;
		// iterate on the path, create all necessary TreeNodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new TreeNode(values[i]);
				else
					assert(current->left->val == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new TreeNode(values[i]);
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
	}
};


class Solution {
public:
	// O(n). Think like preorder traversal
	bool is_mirror(TreeNode* first, TreeNode* second) {
		if (!first && !second)
			return true;

		if (!first && second || first && !second || first->val != second->val)
			return false;	// one subtree only or different values

		// 2 trees will have 4 sub-trees. We need to make sure of 2 mirroring
		return is_mirror(first->left, second->right) && is_mirror(first->right, second->left);
	}


    bool isSymmetric(TreeNode* root) {
        if(!root)
        	return false;

        return is_mirror(root->left, root->right);
    }
};

int main() {	// rename like main1 for leetcode
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	cout << Solution().isSymmetric(tree.root) << "\n";

	return 0;
}

