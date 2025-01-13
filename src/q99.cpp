// 给定一个二叉查找树，已知有两个节点被不小心交换了，试复原此树。

#include "include/head.h"

class Solution {
   public:
    void recoverTree(TreeNode* root) {
        TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;
        inorder(root, mistake1, mistake2, prev);
        if (mistake1 && mistake2) {
            int temp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = temp;
        }
    }
    void inorder(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2,
                 TreeNode*& prev) {
        if (!root) {
            return;
        }
        if (root->left) {
            inorder(root->left, mistake1, mistake2, prev);
        }
        if (prev && root->val < prev->val) {
            if (!mistake1) {
                mistake1 = prev;
                mistake2 = root;
            } else {
                mistake2 = root;
            }
            std::cout << mistake1->val;
            std::cout << mistake2->val;
        }
        prev = root;
        if (root->right) {
            inorder(root->right, mistake1, mistake2, prev);
        }
    }
};