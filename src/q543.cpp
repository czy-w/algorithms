// 求一个二叉树的最长直径。直径的定义是二叉树上任意两节点之间的无向距离。
#include "include/head.h"

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
    int helper(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int l = helper(node->left, diameter), r = helper(node->right, diameter);
        diameter = std::max(l + r, diameter);
        return std::max(l, r) + 1;
    }
};
