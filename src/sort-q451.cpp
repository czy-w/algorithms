//  给定一个非负整数数组 nums，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
// Time complexity: O(n)
// Space complexity: O(1)
// Key points:
// 1. Use greedy algorithm

#include "include/head.h"

// The jump function uses a greedy approach to find the minimum number of jumps required to reach the end of the array.
// The function keeps track of the current position and the farthest position that can be reached from the current position.    
// If the current position is already at the end of the array, we return the current jump count.
// Otherwise, we update the farthest position that can be reached from the current position by comparing it with the current position plus the current jump count.            
// If the current position plus the current jump count is greater than the farthest position that can be reached from the current position, we update the farthest position.
// We then decrement the current jump count and continue the loop until the current position is at the end of the array.            
// Finally, we return the current jump count, which represents the minimum number of jumps required to reach the end of the array.
// Key features:
// Efficient O(n) time complexity by using a greedy approach
// O(1) space complexity as we only use a few variables
// Handles all edge cases:
// Array with only one element
// Array with only one element that is not the last element
// Array with only one element that is the last element
// Array with multiple elements
// Array with multiple elements that are not the last element
// Array with multiple elements that are the last element
// Handles all edge cases by using a greedy approach            
// Time complexity: O(n) where n is the length of the array
// Space complexity: O(1)       

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int current = 0;
        int farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == current) {
                jumps++;
                current = farthest;
            }
        }
        
        return jumps;
    }
};  


int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    Solution solution;
    int result = solution.jump(nums);
    std::cout << "Minimum number of jumps: " << result << std::endl;
    return 0;
}   