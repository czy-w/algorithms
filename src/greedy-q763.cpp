// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
// 返回一个表示每个字符串片段的长度的列表.

#include "include/head.h"

// 思路：
// 1. 首先遍历字符串，记录每个字符最后出现的位置
// 2. 再次遍历字符串，维护当前片段的结束位置：
//    - 对于当前遍历到的字符，更新当前片段的结束位置（取最大值）
//    - 如果遍历到的位置等于当前片段的结束位置，说明找到了一个完整的片段

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> last_pos(26, 0);  // 记录每个字母最后出现的位置
        
        // 记录每个字符最后出现的位置
        for (int i = 0; i < s.length(); i++) {
            last_pos[s[i] - 'a'] = i;
        }
        
        std::vector<int> result;
        int start = 0;  // 当前片段的起始位置
        int end = 0;    // 当前片段的结束位置
        
        // 遍历字符串，划分片段
        for (int i = 0; i < s.length(); i++) {
            // 更新当前片段的结束位置
            end = std::max(end, last_pos[s[i] - 'a']);
            
            // 如果到达当前片段的结束位置
            if (i == end) {
                result.push_back(end - start + 1);  // 添加当前片段的长度
                start = i + 1;  // 更新下一个片段的起始位置
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    std::string s1 = "ababcbacadefegdehijhklij";
    std::vector<int> result1 = solution.partitionLabels(s1);
    // 应该输出 [9,7,8]
    for (int len : result1) {
        std::cout << len << " ";
    }
    std::cout << std::endl;
    
    std::string s2 = "eccbbbbdec";
    std::vector<int> result2 = solution.partitionLabels(s2);
    // 应该输出 [10]
    for (int len : result2) {
        std::cout << len << " ";
    }
    std::cout << std::endl;
    
    return 0;
}