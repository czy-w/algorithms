// 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
// 输入是一个数组，数组由多个长度固定为的数组组成，表示区间的开始和结尾。输出一个
// 整数，表示需要移除的区间数量。

#include "include/head.h"

// 首先按照区间的结束时间进行排序
// 选择第一个区间（结束时间最早的区间）
// 遍历剩余区间：
// 如果当前区间的开始时间小于前一个选中区间的结束时间，说明有重叠，需要移除当前区间
// 否则，选择当前区间，更新结束时间

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // 按区间结束时间排序
        sort(intervals.begin(), intervals.end(), 
             [](const std::vector<int>& a, const std::vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int count = 0;          // 需要移除的区间数量
        int end = intervals[0][1];  // 当前选中区间的结束时间
        
        // 遍历所有区间
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {  // 如果当前区间与前一个选中的区间重叠
                count++;  // 需要移除当前区间
            } else {
                end = intervals[i][1];  // 更新结束时间
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> intervals1 = {{1,2}, {2,3}, {3,4}, {1,3}};
    std::cout << solution.eraseOverlapIntervals(intervals1) << std::endl;  // 应该输出1
    
    std::vector<std::vector<int>> intervals2 = {{1,2}, {1,2}, {1,2}};
    std::cout << solution.eraseOverlapIntervals(intervals2) << std::endl;  // 应该输出2
}