// 给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。

#include "include/head.h"

// isSubsequence 函数：使用双指针判断一个字符串是否是另一个字符串的子序列
// i 指向源字符串 s
// j 指向目标字符串 word
// 如果找到匹配字符，j 前进一步
// i 总是前进一步
// 最后检查是否遍历完整个 word
// findLongestWord 函数:
// 首先对字典进行排序，按照长度降序和字典序升序排序
// 遍历排序后的字典，返回第一个是源字符串子序列的单词

class Solution {
public:
    bool isSubsequence(const std::string& s, const std::string& word) {
        int i = 0, j = 0;
        while (i < s.length() && j < word.length()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.length();
    }

    std::string findLongestWord(std::string s, std::vector<std::string>& dictionary) {
        std::sort(dictionary.begin(), dictionary.end(), 
            [](const std::string& a, const std::string& b) {
                return a.length() > b.length() || 
                       (a.length() == b.length() && a < b);
            });
        
        for (const std::string& word : dictionary) {
            if (isSubsequence(s, word)) {
                return word;
            }
        }
        
        return "";
    }
};

int main() {
    Solution solution;
    std::string s = "abpcplea";
    std::vector<std::string> dictionary = {"ale", "apple", "monkey", "plea"};
    
    std::string result = solution.findLongestWord(s, dictionary);
    std::cout << "最长的匹配单词是: " << result << std::endl;
    
    // 测试用例2
    s = "abpcplea";
    dictionary = {"a", "b", "c"};
    result = solution.findLongestWord(s, dictionary);
    std::cout << "最长的匹配单词是: " << result << std::endl;
    
    return 0;
}