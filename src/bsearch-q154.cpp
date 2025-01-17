// Find Minimum in Rotated Sorted Array II
// Array may contain duplicates
// Time complexity: O(log n) average case, O(n) worst case with duplicates
// Space complexity: O(1)
// Key points:
// 1. Handle duplicates by skipping them
// 2. Compare with rightmost element to determine which half to search
// 3. Special case when nums[mid] == nums[right]

#include "include/head.h"

// The findMin function uses a modified binary search approach:
// Compare the middle element with the rightmost element to determine which half to search
// When nums[mid] > nums[right], minimum is in right half
// When nums[mid] < nums[right], minimum is in left half (including mid)
// When nums[mid] == nums[right], we can't determine which half, so we decrement right
// Key features:
// Handles duplicates by carefully shrinking the search space
// Time complexity: O(log n) in average case, but can degrade to O(n) in worst case with many duplicates
// Space complexity: O(1)

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than rightmost element,
            // minimum is in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // If mid element is less than rightmost element,
            // minimum is in left half (including mid)
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            // If they are equal, we can't determine which half,
            // but we know right can't be the minimum (since mid equals it)
            else {
                right--;
            }
        }
        
        return nums[left];
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2,2,2,0,1};
    
    int result = solution.findMin(nums);
    std::cout << "Minimum element in rotated array: " << result << std::endl;
    
    return 0;
}