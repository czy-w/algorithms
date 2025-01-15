// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表。
// 要求：时间复杂度O(n log n)，空间复杂度O(1)
// 例如：
// 输入：head = [4,2,1,3] 输出：[1,2,3,4]
// 输入：head = [-1,5,3,4,0] 输出：[-1,0,3,4,5]

#include "include/head.h"

// 思路：使用归并排序
// 1.分割链表：
// 使用快慢指针找到链表中点
// 快指针每次移动两步，慢指针每次移动一步
// 当快指针到达末尾时，慢指针指向中点
// 在中点处断开链表，得到两个子链表
// 2.递归排序：
// 对左半部分递归调用sortList
// 对右半部分递归调用sortList
// 递归的基本情况是链表为空或只有一个节点
// 3.合并有序链表：
// 使用之前在21题中实现的mergeTwoLists函数
// 用哨兵节点简化头节点的处理
// 比较两个链表的节点值，将较小的节点连接到结果链表
// 时间复杂度O(n log n)，空间复杂度O(log n)用于递归栈

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 空链表或只有一个节点，直接返回
        if (!head || !head->next) return head;
        
        // 使用快慢指针找到中点
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 分割链表
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        // 递归排序两半
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // 合并两个有序链表
        return mergeTwoLists(left, right);
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1：4->2->1->3
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(3);
    
    std::cout << "Test case 1 before: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head1 = solution.sortList(head1);
    
    std::cout << "Test case 1 after: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 测试用例2：-1->5->3->4->0
    ListNode* head2 = new ListNode(-1);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(0);
    
    std::cout << "Test case 2 before: ";
    for (ListNode* p = head2; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head2 = solution.sortList(head2);
    
    std::cout << "Test case 2 after: ";
    for (ListNode* p = head2; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 清理内存
    while (head1) {
        ListNode* temp = head1;
        head1 = head1->next;
        delete temp;
    }
    
    while (head2) {
        ListNode* temp = head2;
        head2 = head2->next;
        delete temp;
    }
    
    return 0;
}
