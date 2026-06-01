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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> list{};
        std::vector<int> rightSideView{};

        list.push(root);
        while (!list.empty()) {
            auto size = list.size();

            for (int index = 0; index < size; ++index) {
                auto* node = list.front();
                if (!node) {
                    list.pop();
                    continue;
                }
                if (node->left) list.push(node->left);
                if (node->right) list.push(node->right);
                if (index == size - 1) rightSideView.push_back(node->val);
                list.pop();
            }
        }
        return rightSideView;
    }
};
