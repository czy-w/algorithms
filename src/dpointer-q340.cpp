// 给定一个字符串 s 和一个整数 k，找到至多包含 k 个不同字符的最长子串的长度。

#include "include/head.h"

// 使用哈希表（unordered_map）记录窗口中每个字符的出现次数
// 使用双指针（left 和 right）维护一个滑动窗口：
// right 指针不断向右扩展窗口
// 当窗口中不同字符的数量超过 k 时，left 指针向右收缩窗口
// 在整个过程中维护最大长度 maxLen

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k) {
        if (k == 0) return 0;
        
        // 使用哈希表记录窗口中每个字符的出现次数
        std::unordered_map<char, int> window;
        int maxLen = 0;
        int left = 0, right = 0;
        
        while (right < s.length()) {
            // 扩展窗口
            window[s[right]]++;
            right++;
            
            // 当窗口中不同字符的数量超过k时，收缩窗口
            while (window.size() > k) {
                window[s[left]]--;
                if (window[s[left]] == 0) {
                    window.erase(s[left]);
                }
                left++;
            }
            
            // 更新最大长度
            maxLen = std::max(maxLen, right - left);
        }
        
        return maxLen;
    }
};

int main() {
    Solution solution;
    std::string s = "eceba";
    int k = 2;
    
    int result = solution.lengthOfLongestSubstringKDistinct(s, k);
    std::cout << "最长子串的长度: " << result << std::endl;
    
    // 测试用例2
    s = "aa";
    k = 1;
    result = solution.lengthOfLongestSubstringKDistinct(s, k);
    std::cout << "最长子串的长度: " << result << std::endl;
    
    return 0;
}