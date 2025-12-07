// https://leetcode.com/problems/flip-equivalent-binary-trees

#include <iostream>
#include <sstream>	// ostringstream
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

string toStr(int n) {
	// Convert integer to string
	ostringstream oss;
	oss << n;
	return oss.str();
}

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
	string _parenthesize_canonical(TreeNode *root) {
		if (!root)
			return "()";

		string repr = "(" + toStr(root->val);

		vector<string> v;

		if (left)
			v.push_back(_parenthesize_canonical(root->left));
		else
			v.push_back("()");

		if (right)
			v.push_back(_parenthesize_canonical(root->right));
		else
			v.push_back("()");

		sort(v.begin(), v.end());
		for (int i = 0; i < (int) v.size(); ++i)
			repr += v[i];

		repr += ")";

		return repr;
	}

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		// This is a direct canonical problem!
		return _parenthesize_canonical(root1) == _parenthesize_canonical(root2);
		// We can also develop a recursive code that is based on
		// is_flip_equiv(left, other->left) && is_flip_equiv(right, other->right) ||
		// is_flip_equiv(left, other->right) && is_flip_equiv(right, other->left);
		// O(min(n, m)) where n & m are the 2 trees number of nodes
		// This is NOT O(n^2) code. Think like preorder traversal
    }
};

int main() {	// rename like main1 for leetcode
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	return 0;
}

