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
    int findMax(TreeNode* root) {
      if (!root) 
        return INT_MIN;
      // return maximum of 3 values
      int maxValue = root->val;
      int leftMaxValue = findMax(root->left);
      int rightMaxValue = findMax(root->right);

      if (leftMaxValue > maxValue)
        maxValue = leftMaxValue;
      if (rightMaxValue > maxValue)
        maxValue = rightMaxValue;
      return maxValue;    
    }  
    
    //cleaner version
    int findMax_v2(TreeNode* root) {
      if(!root)
        return INT_MIN;
      return max(root->val, max(findMax_v2(root->left), findMax_v2(root->right)));
    }
};