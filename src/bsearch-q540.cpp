// Single Element in a Sorted Array
// All elements appear exactly twice except for one element which appears exactly once
// Time complexity: O(log n)
// Space complexity: O(1)
// Key points:
// 1. Use binary search to find the single element
// 2. Check if mid is even or odd index
// 3. Compare with adjacent elements to determine which half to search

#include "include/head.h"

// The singleNonDuplicate function uses binary search with these key insights:
// For elements before the single element, first occurrence is at even index
// For elements after the single element, first occurrence is at odd index
// Use this pattern to determine which half to search
// Handle edge cases (single element at start or end)
// Key features:
// Efficient O(log n) time complexity by using binary search
// O(1) space complexity as we only use a few variables
// Handles all edge cases:
// Array with only one element
// Single element at start or end
// Single element in middle

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Handle edge cases
        if (right == 0) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[right] != nums[right - 1]) return nums[right];
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If mid is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            
            // If mid is even, it should match with next element
            // If mid is odd, it should match with previous element
            // If this pattern is violated, single element is in left half
            if ((mid % 2 == 0 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid + 1])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return nums[left];  // This line should never be reached given problem constraints
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1,1,2,3,3,4,4,8,8};
    
    int result = solution.singleNonDuplicate(nums);
    std::cout << "Single element in array: " << result << std::endl;
    
    return 0;
}