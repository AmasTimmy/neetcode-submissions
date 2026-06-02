/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  static int getGoodNodes(TreeNode* root, int max) {
    if (!root) return 0;

    if (root->val >= max) {
        return 1 + getGoodNodes(root->left, root->val) + getGoodNodes(root->right, root->val);
    } else {
        return getGoodNodes(root->left, max) + getGoodNodes(root->right, max);
    }
  }

 public:
  int goodNodes(TreeNode* root) {
    return getGoodNodes(root, -101);
  }
};
