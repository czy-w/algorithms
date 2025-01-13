// 判断一个二叉树是否平衡。树平衡的定义是，对于树上的任意节点，其两侧节点的最大深度的差值不得大于。
#include "include/head.h"

class Solution {
   public:
    bool isBalanced(TreeNode* root) { return helper(root) != -1; }
    // 辅函数
    int helper(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return 1 + std::max(left, right);
    }
};