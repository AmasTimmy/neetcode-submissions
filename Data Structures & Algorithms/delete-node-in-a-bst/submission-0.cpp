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
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (root->left && !root->right) {
                return root->left;
            }
            if (!root->left && root->right) {
                return root->right;
            }

            auto* currentNode = root->right;
            while (currentNode->left) {
                currentNode = currentNode->left;
            }
            currentNode->right = deleteNode(root->right, currentNode->val);
            currentNode->left = root->left;
            delete root;
            return currentNode;
        }
    }
};