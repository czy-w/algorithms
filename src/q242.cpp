// 判断两个字符串包含的字符是否完全相同。
#include "include/head.h"

class Solution {
   public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::vector<int> counts(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (counts[i]) {
                return false;
            }
        }
        return true;
    }
};
