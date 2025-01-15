// 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
// 个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
// 有孩子至少要有一个糖果。求解最少需要多少个糖果。输入是一个数组，表示孩子的评分。输出是最少糖果的数量。

#include "include/head.h"

// 第一次从左向右遍历，确保右边评分高的孩子比左边的孩子获得更多糖果
// 第二次从右向左遍历，确保左边评分高的孩子比右边的孩子获得更多糖果
// 最后计算总和得到最少需要的糖果数量

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1);  // 初始每个孩子分配1个糖果
        
        // 从左向右遍历，确保右边评分高的孩子比左边多
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // 从右向左遍历，确保左边评分高的孩子比右边多
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = std::max(candies[i], candies[i+1] + 1);
            }
        }
        
        // 计算总糖果数
        int total = 0;
        for (int candy : candies) {
            total += candy;
        }
        return total;
    }
};

int main() {
    Solution solution;
    std::vector<int> ratings = {1,0,2};  // 测试用例
    std::cout << solution.candy(ratings) << std::endl;  // 应该输出5
    
    std::vector<int> ratings2 = {1,2,2};  // 测试用例2
    std::cout << solution.candy(ratings2) << std::endl;  // 应该输出4
}