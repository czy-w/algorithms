// 给定两个有序数组，把两个数组合并为一个。
// 假设第一个数组有足够的空间容纳第二个数组的元素

#include "include/head.h"

// 使用双指针技巧，但是从后往前合并，这样可以避免覆盖 nums1 中的有效元素
// 使用三个指针：
// p1：指向 nums1 的有效元素末尾
// p2：指向 nums2 的末尾
// p：指向合并后数组的末尾位置
// 比较两个数组的元素，将较大的放在合并后数组的末尾，然后相应的指针向前移动
// 时间复杂度为 O(m+n)，空间复杂度为 O(1)

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // 从后往前合并，这样可以避免覆盖nums1中的元素
        int p1 = m - 1;    // nums1的有效元素指针
        int p2 = n - 1;    // nums2的指针
        int p = m + n - 1; // 合并后的位置指针

        while (p2 >= 0) {  // 只要nums2还有元素需要合并
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};  // 预留了足够的空间
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3;  // nums1中有效元素的个数
    int n = 3;  // nums2的元素个数
    
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    
    // 打印合并后的结果
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}