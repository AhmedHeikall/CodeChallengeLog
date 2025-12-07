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


struct BinarySearchTree {
	TreeNode* root { };
	BinarySearchTree(int root_value) :
			root(new TreeNode(root_value)) {
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode* current = this->root;
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

	void _print_inorder(TreeNode* current) {
		if (!current)
			return;
		_print_inorder(current->left);
		cout << current->val << " ";
		_print_inorder(current->right);
	}


	void print_inorder() {
		_print_inorder(root);
		cout << "\n";
	}

	bool _search(TreeNode* root, int target) {	// tail recursion
		if(!root)
			return false;

		if (target == root->val)
			return true;

		if (target < root->val)
			return _search(root->left, target);

		return _search(root->right, target);
	}

	bool search(int target) {
		return _search(root, target);
	}

	void _insert(TreeNode* root, int target) {
		if (target < root->val) {
			if (!root->left)
				root->left = new TreeNode(target);
			else
				_insert(root->left, target);
		} else if(target > root->val){
			if (!root->right)
				root->right = new TreeNode(target);
			else
				_insert(root->right, target);
		} // else: exists already
	}

	void insert(int target) {
		if (!root)
			root = new TreeNode(target);
		else
			_insert(root, target);
	}

	// Modified search: Return chain of ancestors from root to target
	bool find_chain(TreeNode* root, int target, vector<TreeNode*> &ancestors) {
		ancestors.push_back(root);

		if (target == root->val)
			return true;

		if (target < root->val)
			return find_chain(root->left, target, ancestors);

		return root->right && find_chain(root->right, target, ancestors);
	}

	int min_value(TreeNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur->val;
	}

	TreeNode* get_next(vector<TreeNode*> &ancestors) {
		if (ancestors.size() == 0)
			return nullptr;
		TreeNode* node = ancestors.back();	// last element
		ancestors.pop_back();
		return node;
	}

	pair<bool, int> successor(int target) {
		vector<TreeNode*> ancestors;

		if (!find_chain(root, target, ancestors))	// not exist
			return make_pair(false, -1);

		TreeNode* child = get_next(ancestors);

		if (child->right)	// must have it in min of right
			return make_pair(true, min_value(child->right));

		TreeNode* parent = get_next(ancestors);

		// Cancel chain of ancestors I am BIGGER than them
		while (parent && parent->right == child)
			child = parent, parent = get_next(ancestors);

		if (parent)	//
			return make_pair(true, parent->val);
		return make_pair(false, -1);
	}

};

int main() {
	BinarySearchTree tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);

	vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 };

	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
		pair<bool, int> p = tree.successor(v[i]);

		if (p.first)
			cout << p.second << "\n";
		else
			cout << "NA\n";

	}

	return 0;
}

