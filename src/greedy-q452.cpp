// 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，
// 其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。
// 你不知道气球的确切 y 坐标。一支弓箭可以沿着X 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，
// 若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，
// 则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
// 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

#include "include/head.h"

// 思路：
// 1. 按照气球的结束位置排序
// 2. 用一支箭尽可能多地引爆气球：
//    - 如果当前气球的开始位置大于上一支箭的位置，需要新箭
//    - 否则可以用同一支箭引爆

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) return 0;
        
        // 按结束位置排序
        sort(points.begin(), points.end(), 
             [](const std::vector<int>& a, const std::vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int arrows = 1;  // 至少需要一支箭
        int arrow_pos = points[0][1];  // 第一支箭的位置（射在第一个气球的结束位置）
        
        // 遍历所有气球
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > arrow_pos) {  // 如果当前气球的开始位置大于箭的位置
                arrows++;  // 需要新的箭
                arrow_pos = points[i][1];  // 更新箭的位置
            }
        }
        
        return arrows;
    }
};

int main() {
    Solution solution;
    
    std::vector<std::vector<int>> points1 = {{10,16}, {2,8}, {1,6}, {7,12}};
    std::cout << solution.findMinArrowShots(points1) << std::endl;  // 应该输出2
    
    std::vector<std::vector<int>> points2 = {{1,2}, {3,4}, {5,6}, {7,8}};
    std::cout << solution.findMinArrowShots(points2) << std::endl;  // 应该输出4
    
    return 0;
}