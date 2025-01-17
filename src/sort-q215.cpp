// 在一个未排序的数组中，找到第k大的数字。

#include "include/head.h"

// Find Kth Largest Element in an Array
// Using QuickSelect algorithm (optimized version of QuickSort)
// Average Time complexity: O(n)
// Worst Time complexity: O(n^2)
// Space complexity: O(1)
// Key points:
// 1. Use QuickSelect to partition array
// 2. Only recurse on the half that contains kth largest
// 3. Random pivot selection to avoid worst case

class Solution {
private:
    int partition(std::vector<int>& nums, int left, int right) {
        // Choose random pivot to avoid worst case scenario
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];
        
        // Move pivot to end
        std::swap(nums[pivotIndex], nums[right]);
        
        // Move all elements smaller than pivot to left side
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                std::swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        
        // Move pivot to its final place
        std::swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
    
    int quickSelect(std::vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        int pivotIndex = partition(nums, left, right);
        
        // Count elements from right that are greater than or equal to pivot
        int count = right - pivotIndex + 1;
        
        // If we found kth largest
        if (count == k) return nums[pivotIndex];
        // If we have more elements than k on the right side
        if (count > k) return quickSelect(nums, pivotIndex + 1, right, k);
        // If we need to look in left side
        return quickSelect(nums, left, pivotIndex - 1, k - count);
    }
    
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        srand(time(0));  // Initialize random seed
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    
    int result = solution.findKthLargest(nums, k);
    std::cout << k << "th largest element: " << result << std::endl;
    
    return 0;
}
