// 给定一个整数二叉树，求有多少条路径节点值的和等于给定值。
#include "include/head.h"

class Solution {
   public:
    // 主函数
    int pathSum(TreeNode* root, int sum) {
        return root ? pathSumStartWithRoot(root, sum) +
                          pathSum(root->left, sum) + pathSum(root->right, sum)
                    : 0;
    }
    // 辅函数
    int pathSumStartWithRoot(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        int count = root->val == sum ? 1 : 0;
        count += pathSumStartWithRoot(root->left, sum - root->val);
        count += pathSumStartWithRoot(root->right, sum - root->val);
        return count;
    }
};