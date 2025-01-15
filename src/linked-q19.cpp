// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 例如：
// 输入：head = [1,2,3,4,5], n = 2  输出：[1,2,3,5]
// 输入：head = [1], n = 1  输出：[]
// 输入：head = [1,2], n = 1  输出：[1]

#include "include/head.h"

// 思路：
// 使用三个指针：
// odd：指向奇数位置节点
// even：指向偶数位置节点
// evenHead：保存偶数链表的头节点（用于最后连接）
// 遍历链表时：
// 将奇数位置节点相连：odd->next = even->next
// 将偶数位置节点相连：even->next = odd->next
// 移动指针：odd = odd->next, even = even->next
// 最后将奇数链表与偶数链表相连：odd->next = evenHead
// 使用快慢指针，快指针先走n步
// 然后快慢指针一起走，直到快指针到达末尾
// 此时慢指针指向要删除节点的前一个节点
// 使用哨兵节点处理删除头节点的情况
// 时间复杂度O(n)，空间复杂度O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建哨兵节点，处理删除头节点的情况
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // 快指针先走n步
        for (int i = 0; i < n; i++) {
            if (!fast->next) return head; // n大于链表长度
            fast = fast->next;
        }
        
        // 快慢指针一起走，直到快指针到达末尾
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 删除倒数第n个节点
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        head = dummy.next;
        return head;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1：1->2->3->4->5，删除倒数第2个节点
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    std::cout << "Test case 1 before: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head1 = solution.removeNthFromEnd(head1, 2);
    
    std::cout << "Test case 1 after: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 测试用例2：1->2，删除倒数第1个节点
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    std::cout << "Test case 2 before: ";
    for (ListNode* p = head2; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head2 = solution.removeNthFromEnd(head2, 1);
    
    std::cout << "Test case 2 after: ";
    for (ListNode* p = head2; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 测试用例3：1，删除倒数第1个节点
    ListNode* head3 = new ListNode(1);
    
    std::cout << "Test case 3 before: ";
    for (ListNode* p = head3; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head3 = solution.removeNthFromEnd(head3, 1);
    
    std::cout << "Test case 3 after: ";
    for (ListNode* p = head3; p != nullptr; p = p->next) {
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
    
    // head3已经被完全删除，不需要清理
    
    return 0;
}
