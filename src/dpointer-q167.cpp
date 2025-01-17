// 在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。

#include "include/head.h"

// 使用双指针技巧，left 指向数组开始，right 指向数组末尾
// 在每一步中：
// 如果两个指针指向的数的和等于目标值，返回这两个位置（注意要加1因为题目要求返回的下标从1开始）
// 如果和小于目标值，说明需要更大的和，因此将左指针右移
// 如果和大于目标值，说明需要更小的和，因此将右指针左移
// 时间复杂度为 O(n)，空间复杂度为 O(1)

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                // 题目要求返回的下标从1开始
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
};


int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}