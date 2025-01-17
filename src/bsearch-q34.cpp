// Find the first and last position of a target element in a sorted array
// If target is not found, return [-1, -1]
// Time complexity: O(log n), Space complexity: O(1)

#include "include/head.h"

// The main function searchRange returns a vector of two integers representing the start and end positions.
// We use a helper function findBound that performs binary search twice:
// Once to find the leftmost occurrence (isFirst = true)
// Once to find the rightmost occurrence (isFirst = false)
// The binary search is modified to continue searching even after finding a match:
// For leftmost position, we continue searching in the left half
// For rightmost position, we continue searching in the right half
// If the target is not found, we return [-1, -1]
// The solution has O(log n) time complexity since we perform binary search twice, and O(1) space complexity.

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result = {-1, -1};
        
        // Find the leftmost position
        result[0] = findBound(nums, target, true);
        
        // Find the rightmost position
        result[1] = findBound(nums, target, false);
        
        return result;
    }
    
private:
    int findBound(std::vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int boundary = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                boundary = mid;
                if (isFirst) {
                    // For first occurrence, continue searching in left half
                    right = mid - 1;
                } else {
                    // For last occurrence, continue searching in right half
                    left = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return boundary;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    std::vector<int> result = solution.searchRange(nums, target);
    std::cout << "First and last position of " << target << ": [" 
         << result[0] << ", " << result[1] << "]" << std::endl;
    
    return 0;
}