// Sort Colors (Dutch National Flag problem). This is a classic sorting problem 
// that requires sorting an array containing only 0s, 1s, and 2s in a single pass.

#include "include/head.h"

// Sort Colors (Dutch National Flag Problem)
// Given array with only 0s, 1s, and 2s, sort them in-place
// Time complexity: O(n) - one pass algorithm
// Space complexity: O(1) - only constant extra space
// Key points:
// 1. Use three pointers: left (0s), current (1s), right (2s)
// 2. Move current pointer and swap elements until right pointer is reached
// 3. Maintain invariant: [0, left) is 0s, [left, current) is 1s, (right, end] is 2s

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int left = 0;           // pointer for 0s
        int current = 0;        // current pointer
        int right = nums.size() - 1;  // pointer for 2s
        
        while (current <= right) {
            if (nums[current] == 0) {
                // If we find a 0, swap with left pointer
                std::swap(nums[left], nums[current]);
                left++;
                current++;
            }
            else if (nums[current] == 2) {
                // If we find a 2, swap with right pointer
                std::swap(nums[current], nums[right]);
                right--;
                // Don't increment current as the swapped element needs to be checked
            }
            else {
                // If we find a 1, just move current pointer
                current++;
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2,0,2,1,1,0};
    
    std::cout << "Original array: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;
    
    solution.sortColors(nums);
    
    std::cout << "Sorted array: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << std::endl;
    
    return 0;
}
