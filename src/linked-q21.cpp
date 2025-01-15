// 给定两个增序的链表，试将其合并成一个增序的链表。
// 例如：输入1->2->4和1->3->4，输出1->1->2->3->4->4

#include "include/head.h"

// 首先处理特殊情况：如果有一个链表为空，直接返回另一个链表
// 创建一个哨兵节点（dummy node），简化插入操作
// 使用一个尾指针（tail）来跟踪当前结果链表的末尾
// 当两个链表都不为空时：
// 比较两个链表当前节点的值
// 将较小的节点连接到结果链表
// 移动较小节点所在的链表指针
// 更新尾指针
// 最后，如果有一个链表还有剩余节点，直接将其连接到结果链表的末尾

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 如果有一个链表为空，直接返回另一个链表
        if (!list1) return list2;
        if (!list2) return list1;
        
        // 创建一个哨兵节点，简化插入操作
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 当两个链表都不为空时，比较节点值并连接较小的节点
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // 将剩余的节点连接到结果链表
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;
    }
};

int main() {
    Solution solution;
    
    // 创建第一个链表：1->2->4
    Solution::ListNode* list1 = new Solution::ListNode(1);
    list1->next = new Solution::ListNode(2);
    list1->next->next = new Solution::ListNode(4);
    
    // 创建第二个链表：1->3->4
    Solution::ListNode* list2 = new Solution::ListNode(1);
    list2->next = new Solution::ListNode(3);
    list2->next->next = new Solution::ListNode(4);
    
    // 合并链表
    Solution::ListNode* merged = solution.mergeTwoLists(list1, list2);
    
    // 打印合并后的链表
    for (Solution::ListNode* p = merged; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 清理内存
    while (merged != nullptr) {
        Solution::ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }
    
    return 0;
}
