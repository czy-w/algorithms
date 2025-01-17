// 给定两个字符串S和T，求S中包含T所有字符的最短连续子字符串的长度，时间复杂度不得超过O(n)。

#include "include/head.h"

// 使用数组 need 记录目标字符串 T 中每个字符需要的数量
// 使用双指针（left 和 right）维护一个滑动窗口：
// right 指针不断向右扩展窗口，寻找包含所需字符的子串
// 当找到一个可行解后，left 指针向右收缩窗口，尝试找到更小的解
// 使用 needCount 记录还需要的字符数量，当它为 0 时表示找到了一个可行解
// 在收缩窗口的过程中，不断更新最小子串的信息（起始位置和长度）
// 这个算法的时间复杂度为 O(n)，空间复杂度为 O(1)（因为使用了固定大小的数组来存储字符计数

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        // 记录目标字符串t中每个字符需要的数量
        std::vector<int> need(128, 0);
        for (char c : t) {
            need[c]++;
        }
        
        // 定义滑动窗口的左右边界
        int left = 0, right = 0;
        // 记录最小子串的起始位置和长度
        int start = 0, minLen = INT_MAX;
        // 记录当前窗口中还需要的字符数量
        int needCount = t.length();
        
        // 右指针不断向右扩展窗口
        while (right < s.length()) {
            // 如果当前字符是需要的字符
            if (need[s[right]] > 0) {
                needCount--;
            }
            // 更新need数组中字符的需求量
            need[s[right]]--;
            right++;
            
            // 当所有字符都已找到，尝试收缩左边界
            while (needCount == 0) {
                // 更新最小子串信息
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                
                // 移动左指针，收缩窗口
                need[s[left]]++;
                if (need[s[left]] > 0) {
                    needCount++;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution solution;
    std::string S = "ADOBECODEBANC";
    std::string T = "ABC";
    
    std::string result = solution.minWindow(S, T);
    std::cout << "最小覆盖子串: " << result << std::endl;
    std::cout << "长度: " << result.length() << std::endl;
    
    return 0;
}