// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
// 例如：输入1->2->3->4，输出2->1->4->3

#include "include/head.h"

// 思路：
// 使用一个哨兵节点（dummy）简化头节点的处理
// 用三个指针：prev（前一个节点）、curr（当前节点）、next（下一个节点）
// 每次交换相邻的两个节点：
// 1. 保存next的下一个节点
// 2. 改变next的指向为curr
// 3. 改变curr的指向为保存的节点
// 4. 改变prev的指向为next

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* swapPairs(ListNode* head) {
        // 如果链表为空或只有一个节点，直接返回
        if (!head || !head->next) return head;
        
        // 创建哨兵节点
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next && prev->next->next) {
            // 获取要交换的两个节点
            ListNode* curr = prev->next;
            ListNode* next = curr->next;
            
            // 保存next的下一个节点
            ListNode* temp = next->next;
            
            // 交换节点
            next->next = curr;
            curr->next = temp;
            prev->next = next;
            
            // 移动prev到下一对节点的前面
            prev = curr;
        }
        
        return dummy.next;
    }
};

int main() {
    Solution solution;
    
    // 创建测试链表：1->2->3->4
    Solution::ListNode* head = new Solution::ListNode(1);
    head->next = new Solution::ListNode(2);
    head->next->next = new Solution::ListNode(3);
    head->next->next->next = new Solution::ListNode(4);
    
    // 打印原始链表
    std::cout << "Original list: ";
    for (Solution::ListNode* p = head; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 交换节点
    Solution::ListNode* swapped = solution.swapPairs(head);
    
    // 打印交换后的链表
    std::cout << "Swapped list: ";
    for (Solution::ListNode* p = swapped; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 清理内存
    while (swapped != nullptr) {
        Solution::ListNode* temp = swapped;
        swapped = swapped->next;
        delete temp;
    }
    
    return 0;
}