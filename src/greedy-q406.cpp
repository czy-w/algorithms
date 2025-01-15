// 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
// 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
// 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
// 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

#include "include/head.h"

// 思路：
// 1. 先按身高h降序排序，同身高的按k值升序排序
// 2. 然后按照k值将每个人插入到对应位置
// 这样的贪心策略可行是因为：
// - 身高高的人只会看到比他高或等高的人
// - 身高矮的人不会影响身高高的人的k值
// - 所以我们可以先安排高的人，再插入矮的人

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        // 按身高降序排序，同身高按k值升序排序
        sort(people.begin(), people.end(), 
             [](const std::vector<int>& a, const std::vector<int>& b) {
                 return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
             });
        
        std::vector<std::vector<int>> result;
        // 按照k值插入到对应位置
        for (const auto& person : people) {
            result.insert(result.begin() + person[1], person);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    std::vector<std::vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    auto result = solution.reconstructQueue(people);
    
    // 输出重建后的队列
    for (const auto& person : result) {
        std::cout << "[" << person[0] << "," << person[1] << "] ";
    }
    std::cout << std::endl;  // 应该输出 [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    
    return 0;
}