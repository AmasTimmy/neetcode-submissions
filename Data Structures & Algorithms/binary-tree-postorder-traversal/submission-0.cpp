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
    void preorderTraversalInserter(TreeNode* root, std::vector<int>& list) {
        if (!root) return;
        preorderTraversalInserter(root->left, list);
        preorderTraversalInserter(root->right, list);
        list.push_back(root->val);
    }

   public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> traversalList{};
        preorderTraversalInserter(root, traversalList);

        return traversalList;
    }
};