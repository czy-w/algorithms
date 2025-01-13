#include "include/head.h"

class Solution {
public:
 bool canJump(const std::vector<int>& nums) {
     int n = nums.size();
     int reachable = 0;
     for (int i = 0; i < n; ++i) {
         if (i > reachable) {
             return false;
         }
         reachable = std::max(reachable, i + nums[i]);
         if (reachable >= n - 1) {
             return true;
         }
     }
     return false;
 }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 0, 0};
    if (solution.canJump(nums)) {
        std::cout << "This is true" << std::endl;
    } else {
        std::cout << "This is false" << std::endl;
    }
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}