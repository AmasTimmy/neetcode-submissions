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
  int m_min = -1001;
  static bool preorderTraversal(TreeNode* root, int& prev) {
    if (!root) return true;
    auto left = preorderTraversal(root->left, prev);
    if (!left || prev >= root->val) return false;
    prev = root->val;
    auto right = preorderTraversal(root->right, prev);
    return left && right;
  }

 public:
  bool isValidBST(TreeNode* root) {
    return preorderTraversal(root, m_min);
  }
};
