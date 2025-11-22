#include <iostream>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int goodNodes(TreeNode* root, int maxSoFar) {
        if (!root)
          return 0;

        int addme = root->val >= maxSoFar;
        int l = goodNodes(root->left, max(maxSoFar, root->val));
        int r = goodNodes(root->right, max(maxSoFar, root->val));
        return addme + l + r;
            
    } 
    int goodNodes(TreeNode* root) {
        if (!root)
          return 0;
        return goodNodes(root, root->val);  
    }
};