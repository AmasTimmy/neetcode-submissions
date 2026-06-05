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
    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right && root->val + sum == targetSum) return true;
        if (dfs(root->left, targetSum, sum + root->val)) return true;

        if (dfs(root->right, targetSum, sum + root->val)) return true;

        return false;
    }

   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return dfs(root, targetSum, 0);
    }
};