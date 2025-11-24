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
    bool isFull(TreeNode* root) {
      // case 1 no node
      if (!root)
        return false;
      // case 2 is leaf 
      if (!root->left && !root->right)
        return true;  
      // case 3 
      if ((root->left && !root->right)||(!root->left && root->right))  
        return false;
      return isFull(root->left) && isFull(root->right);  
    }
};