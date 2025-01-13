// 给定一个二叉树，求每一层的节点值的平均数。

#include "include/head.h"

class Solution {
   public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ans;
        if (!root) {
            return ans;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            double sum = 0;
            for (int i = 0; i < count; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(sum / count);
        }
        return ans;
    }
};