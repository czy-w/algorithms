// 给定一个已排序的链表的头节点，删除所有重复的元素，使每个元素只出现一次。
// 返回已排序的链表。
// 例如：
// 输入：1->1->2 输出：1->2
// 输入：1->1->2->3->3 输出：1->2->3

#include "include/head.h"

// 思路：
// 由于链表已经排序，所以相同的元素一定相邻
// 使用一个指针遍历链表，比较当前节点和下一个节点的值：
// - 如果值相同，删除下一个节点
// - 如果值不同，移动到下一个节点
// 时间复杂度O(n)，空间复杂度O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* current = head;
        
        while (current && current->next) {
            if (current->val == current->next->val) {
                // 存在重复元素，删除下一个节点
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                // 不存在重复，移动到下一个节点
                current = current->next;
            }
        }
        
        return head;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1：1->1->2
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);
    
    std::cout << "Test case 1 before: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head1 = solution.deleteDuplicates(head1);
    
    std::cout << "Test case 1 after: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 测试用例2：1->1->2->3->3
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);
    
    std::cout << "Test case 2 before: ";
    for (ListNode* p = head2; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head2 = solution.deleteDuplicates(head2);
    
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