// 给定一个整数二叉树和一些整数，求删掉这些整数对应的节点后，剩余的子树

#include "include/head.h"

class Solution {
   public:
    std::vector<TreeNode*> delNodes(TreeNode* root,
                                    std::vector<int>& to_delete) {
        std::vector<TreeNode*> forest;
        std::unordered_set<int> dict(to_delete.begin(), to_delete.end());
        root = helper(root, dict, forest);
        if (root) {
            forest.push_back(root);
        }
        return forest;
    }
    TreeNode* helper(TreeNode* root, std::unordered_set<int>& dict,
                     std::vector<TreeNode*>& forest) {
        if (!root) {
            return root;
        }
        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);
        if (dict.count(root->val)) {
            if (root->left) {
                forest.push_back(root->left);
            }
            if (root->right) {
                forest.push_back(root->right);
            }
            root = NULL;
        }
        return root;
    }
};