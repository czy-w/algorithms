// 给定一个含有到n整数的数组，每个整数只出现一次，求这个数组最多可以分割成多少个
// 子数组，使得对每个子数组进行增序排序后，原数组也是增序的。

#include "include/head.h"

class Solution {
   public:
    int maxChunksToSorted(std::vector<int>& arr) {
        int chunks = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            cur_max = std::max(cur_max, arr[i]);
            if (cur_max == i) {
                ++chunks;
            }
        }
        return chunks;
    }
};