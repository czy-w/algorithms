// 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。
// 可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
// 给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。
// 另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。

#include "include/head.h"

// 遍历花坛数组，找到所有可以种花的位置
// 对于每个位置i，如果满足以下条件，就可以种花：
// - 当前位置是空的 (flowerbed[i] == 0)
// - 左边是空的 (i == 0 或 flowerbed[i-1] == 0)
// - 右边是空的 (i == flowerbed.size()-1 或 flowerbed[i+1] == 0)
// 如果可以种花，就在当前位置种上花，并计数
// 最后比较计数和需要种的花的数量

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                if (i == 0 || flowerbed[i - 1] == 0) {
                    if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                        count++;
                        i++;
                    }
                }
            }
        }
        return count >= n;
    }
};

int main() {
    Solution s;
    std::vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;
    std::cout << s.canPlaceFlowers(flowerbed, n) << std::endl;
    return 0;
}