#include <iostream>
using namespace std;

struct TreeNode {
  int val {};
  TreeNode* left{};
  TreeNode* right{};
  TreeNode(int val): val(val){}
};

class Solution {
  public:
    int maxDepth(TreeNode* root) {
      if (!root)
        return 0;
      int l = maxDepth(root->left);
      int r = maxDepth(root->right);
      return max(l,r) +1;  
    }
};