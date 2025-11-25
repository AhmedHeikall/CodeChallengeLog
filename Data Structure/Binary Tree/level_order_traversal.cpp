//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
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


	void level_order_traversal1() {
		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);

		while (!nodes_queue.empty()) {
			TreeNode*cur = nodes_queue.front();
			nodes_queue.pop();

			cout << cur->val << " ";
			if (cur->left)
				nodes_queue.push(cur->left);
			if (cur->right)
				nodes_queue.push(cur->right);
		}
		cout << "\n";
	}

	void level_order_traversal2() {
		queue<TreeNode*> nodes_queue;
		nodes_queue.push(root);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout<<"Level "<<level<<": ";
			while(sz--) {
				TreeNode*cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->val << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
	}
};


bool isLeaf(TreeNode *node) {
	return node && !node->left && !node->right;
}


void test1_level_order_traversal1() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });

	tree.level_order_traversal1();
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	tree.level_order_traversal2();
	// Level 0: 1
	// Level 1: 2 3
	// Level 2: 4 5 6 7
	// Level 3: 8 9 10 11 12 13 14 15
}

int main() {
	test1_level_order_traversal1();

	cout << "bye\n";

	return 0;
}
