// 给定一个字符，求其有多少个回文子字符串。回文的定义是左右对称。

#include "include/head.h"

class Solution {
   public:
    int countSubstrings(std::string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count += extendSubstrings(s, i, i);      // 奇数长度
            count += extendSubstrings(s, i, i + 1);  // 偶数长度
        }
        return count;
    }
    int extendSubstrings(std::string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};