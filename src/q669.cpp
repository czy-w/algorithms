// 给定一个二叉查找树和两个整数L和R，且L <
//     R，试修剪此二叉查找树，使得修剪后所有 节点的值都在L R的范围内。

#include "include/head.h"

class Solution {
   public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) {
            return root;
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};