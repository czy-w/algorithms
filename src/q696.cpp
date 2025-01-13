// 给定一个字符串，求有多少非空子字符串的和数量相同。

#include "include/head.h"

class Solution {
   public:
    int countBinarySubstrings(std::string s) {
        int pre = 0, cur = 1, count = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cur;
            } else {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur) {
                ++count;
            }
        }
        return count;
    }
};