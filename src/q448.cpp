// 给定一个长度为n的数组，其中包含范围为到n的整数，有些整数重复了多次，有些整数
// 没有出现，求到n中没有出现过的整数。
#include "include/head.h"

class Solution {
   public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> ans;
        for (const int& num : nums) {
            int pos = abs(num) - 1;
            if (nums[pos] > 0) {
                nums[pos] = -nums[pos];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};