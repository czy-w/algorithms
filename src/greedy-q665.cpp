// 给你一个长度为 n 的整数数组 nums，请你判断在最多改变 1 个元素的情况下，
// 该数组能否变成一个非递减数列。
// 我们是这样定义一个非递减数列的：对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

#include "include/head.h"

// 遍历数组，找到破坏非递减性质的位置（nums[i] > nums[i+1]）
// 当找到这样的位置时，我们有两种修改方式：
// 如果是第一个元素或者nums[i-1] <= nums[i+1]，我们可以把nums[i]降低到nums[i+1]
// 否则，我们只能把nums[i+1]升高到nums[i]
// 如果需要修改的次数超过1次，返回false


class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int count = 0;  // 记录需要修改的次数
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {  // 找到需要修改的位置
                count++;
                if (count > 1) return false;  // 如果需要修改超过一次，返回false
                
                // 如果是第一个元素或者nums[i-1]小于等于nums[i+1]
                // 我们可以把nums[i]降低到nums[i+1]
                if (i == 0 || nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i + 1];
                } else {
                    // 否则我们只能把nums[i+1]升高到nums[i]
                    nums[i + 1] = nums[i];
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    std::vector<int> nums1 = {4,2,3};
    std::cout << std::boolalpha << solution.checkPossibility(nums1) << std::endl;  // 应该输出true
    
    std::vector<int> nums2 = {4,2,1};
    std::cout << std::boolalpha << solution.checkPossibility(nums2) << std::endl;  // 应该输出false
    
    return 0;
}