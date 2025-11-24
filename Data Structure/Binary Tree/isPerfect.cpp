/*
perfect binary tree must have 2-condition
  1- All leaf nodes have the same level
  2- All other nodes have 2 children
*/

#include <iostream>
using namespace std;

struct TreeNode {
  int val {};
  TreeNode* left{};
  TreeNode* right{};
  TreeNode(int val): val(val){}
};

class BT {
  public:
    int maxDepth(TreeNode* root) {
      if (!root)
        return 0;
      int l = maxDepth(root->left);
      int r = maxDepth(root->right);
      
      return max(l, r) + 1;
    }

    bool isPerfect(TreeNode* root, int height) {
      if (!root->left && !root->right)
        return height == 0; // all leaves must be on the same level
      
      if (!root->left && root->right || root->left && !root->right)
        return false; // one child
      
      return isPerfect(root->left, height -1) && isPerfect(root->right, height -1);
    }

    bool isPerfect(TreeNode* root) {
      // height of the BT is max depth - 1
       return isPerfect(root, maxDepth(root) - 1);
    }

};