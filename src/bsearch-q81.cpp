// Search in Rotated Sorted Array II
// The array may contain duplicates
// Time complexity: O(log n) in average case, O(n) in worst case
// Space complexity: O(1)

#include "include/head.h"

// The search function returns a boolean indicating whether the target exists in the array.
// Key points of the implementation:
// Handle duplicates by skipping them when nums[left] == nums[mid] == nums[right]
// Determine which half of the array is sorted
// Use the sorted half to decide which direction to search
// Special considerations:
// Time complexity is O(log n) in the average case, but can degrade to O(n) in the worst case with many duplicates
// Space complexity is O(1)

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates at the edges
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            
            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target is in left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                // Check if target is in right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    
    bool result = solution.search(nums, target);
    std::cout << "Target " << target << " found: " << (result ? "true" : "false") << std::endl;
    
    return 0;
}