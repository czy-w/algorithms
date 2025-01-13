// 输入一个二叉树，输出一个数组，为二叉树前序遍历的结果，

#include "include/head.h"

class Solution {
   public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        if (!root) {
            return ret;
        }
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ret.push_back(node->val);
            if (node->right) {
                s.push(node->right);  // 先右后左，保证左子树先遍历
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return ret;
    }
};