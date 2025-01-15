// 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
// 最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩
// 子可以吃饱。输入两个数组，分别代表孩子的饥饿度和饼干的大小。输出最多有多少孩子可以吃饱的数量。

#include "include/head.h"

// 将孩子的胃口值和饼干尺寸分别排序
// 用最小的饼干尝试满足胃口最小的孩子
// 如果当前饼干不能满足当前孩子，尝试下一个饼干
// 如果当前饼干可以满足当前孩子，同时移动到下一个孩子和下一个饼干
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // g是孩子的胃口值数组
        // s是饼干的尺寸数组
        sort(g.begin(), g.end());  // 将孩子的胃口值排序
        sort(s.begin(), s.end());  // 将饼干的尺寸排序
        
        int child = 0;  // 当前待满足的孩子索引
        int cookie = 0;  // 当前使用的饼干索引
        
        // 当还有孩子和饼干时，继续尝试匹配
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {  // 当前饼干可以满足当前孩子
                child++;  // 移动到下一个孩子
            }
            cookie++;  // 无论是否满足都尝试下一个饼干
        }
        
        return child;  // 返回满足的孩子数量
    }
};


int main() {
    Solution solu;
    std::vector<int> g = {1, 2, 3};
    std::vector<int> s = {1, 1};
    std::cout << solu.findContentChildren(g, s) << std::endl;
}