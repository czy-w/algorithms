// 求一个二叉树的最大深度。

#include "include/head.h"

// 定义TreeNode结构体
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right))
                    : 0;
    }
};