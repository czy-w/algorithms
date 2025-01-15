// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。在每一天，你可以决定是否购买和/或出售股票。
// 你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。返回 你能获得的 最大 利润 。

#include "include/head.h"

// 思路：
// 由于可以在同一天买入和卖出，所以我们可以把所有的上涨交易都做了
// 只要今天价格比昨天高，就可以算入收益
// 例如：[1,2,3,4] 等价于 [1->2] + [2->3] + [3->4] 的收益
// 这种贪心策略可行是因为：
// - 如果后面的价格更高，那么就可以继续持有
// - 如果后面的价格更低，那么今天卖出明天买入更好

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxprofit = 0;
        
        // 遍历价格数组，只要当天价格比前一天高，就把差价加入总利润
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxprofit += prices[i] - prices[i - 1];
            }
        }
        
        return maxprofit;
    }
};

int main() {
    Solution solution;
    
    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::cout << solution.maxProfit(prices1) << std::endl;  // 应该输出7
    
    std::vector<int> prices2 = {1,2,3,4,5};
    std::cout << solution.maxProfit(prices2) << std::endl;  // 应该输出4
    
    std::vector<int> prices3 = {7,6,4,3,1};
    std::cout << solution.maxProfit(prices3) << std::endl;  // 应该输出0
    
    return 0;
}