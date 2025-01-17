// 给定一个非负整数 c，判断是否存在两个数 a 和 b，使得 a² + b² = c。

#include "include/head.h"

// judgeSquareSum 函数：
// left 指针从 0 开始
// right 指针从 sqrt(c) 开始
// 计算 left² + right² 的和：
// 如果等于 c，返回 true
// 如果小于 c，增加 left
// 如果大于 c，减小 right

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 使用双指针，left从0开始，right从sqrt(c)开始
        long left = 0;
        long right = (long)sqrt(c);
        
        while (left <= right) {
            // 计算平方和，注意使用long防止溢出
            long sum = left * left + right * right;
            
            if (sum == c) {
                return true;
            } else if (sum < c) {
                left++;
            } else {
                right--;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> testCases = {5, 4, 3, 2, 1, 0, 25, 100000000};
    
    for (int c : testCases) {
        bool result = solution.judgeSquareSum(c);
        std::cout << c << " " 
                  << (result ? "可以" : "不可以") 
                  << "表示为两个数的平方和" << std::endl;
        
        // 如果可以表示为平方和，找出这些数
        if (result) {
            long left = 0;
            long right = (long)sqrt(c);
            while (left <= right) {
                long sum = left * left + right * right;
                if (sum == c) {
                    std::cout << "找到解: " << left << "² + " 
                              << right << "² = " << c << std::endl;
                    break;
                } else if (sum < c) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}