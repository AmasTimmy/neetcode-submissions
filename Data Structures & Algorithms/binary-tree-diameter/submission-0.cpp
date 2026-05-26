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
    int getParams(TreeNode* root, int& diameter) {
        if (!root) return 0;

        auto depthLeft = getParams(root->left, diameter);
        auto depthRight = getParams(root->right, diameter);

        diameter = max(diameter, depthLeft + depthRight);
        return 1 + max(depthRight, depthLeft);
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getParams(root, diameter);

        return diameter;
    }
};
