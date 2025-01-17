// 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

#include "include/head.h"

// isPalindrome 函数:
// 检查字符串在指定范围内是否是回文
// 使用双指针从两端向中间移动比较字符
// validPalindrome 函数:
// 使用双指针从两端向中间检查
// 当遇到不匹配的字符时，尝试删除左边或右边的字符
// 如果删除任一字符后能形成回文，则返回 true

class Solution {
public:
    // 检查字符串在指定范围内是否是回文
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(std::string s) {
        int left = 0, right = s.length() - 1;
        
        // 从两端向中间检查
        while (left < right) {
            if (s[left] != s[right]) {
                // 遇到不匹配的字符时，尝试删除左边或右边的字符
                return isPalindrome(s, left + 1, right) || 
                       isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        return true;  // 如果没有遇到不匹配的字符，原字符串就是回文
    }
};

int main() {
    Solution solution;
    std::vector<std::string> testCases = {
        "aba",          // true
        "abca",         // true (删除'c')
        "abc",          // false
        "deeee",        // true (删除第一个或最后一个'e')
        "cbbcc"         // true (删除最后一个'c')
    };
    
    for (const std::string& s : testCases) {
        bool result = solution.validPalindrome(s);
        std::cout << "字符串 \"" << s << "\" " 
                  << (result ? "可以" : "不可以") 
                  << "通过最多删除一个字符成为回文串" << std::endl;
    }
    
    return 0;
}