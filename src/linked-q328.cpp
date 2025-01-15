// 给定单链表的头节点 head，将所有索引为奇数位置的节点和索引为偶数位置的节点分别组合在一起，
// 然后返回重新排序的列表。第一个节点的索引被认为是奇数，第二个节点的索引为偶数，以此类推。
// 例如：
// 输入：1->2->3->4->5 输出：1->3->5->2->4
// 输入：2->1->3->5->6->4->7 输出：2->3->6->7->1->5->4

#include "include/head.h"

// 思路：
// 使用两个指针odd和even分别指向奇数位置和偶数位置的节点
// 用evenHead保存偶数链表的头节点
// 遍历链表，将奇数节点和偶数节点分别连接
// 最后将奇数链表的尾部与偶数链表的头部相连
// 时间复杂度O(n)，空间复杂度O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        // odd指向奇数位置节点，even指向偶数位置节点
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // 保存偶数链表的头节点
        
        // 当even和even->next都不为空时继续遍历
        while (even && even->next) {
            // 连接奇数位置节点
            odd->next = even->next;
            odd = odd->next;
            
            // 连接偶数位置节点
            even->next = odd->next;
            even = even->next;
        }
        
        // 将奇数链表与偶数链表相连
        odd->next = evenHead;
        
        return head;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1：1->2->3->4->5
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
    
    head1 = solution.oddEvenList(head1);
    
    std::cout << "Test case 1 after: ";
    for (ListNode* p = head1; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    // 测试用例2：2->1->3->5->6->4->7
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(5);
    head2->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next = new ListNode(4);
    head2->next->next->next->next->next->next = new ListNode(7);
    
    std::cout << "Test case 2 before: ";
    for (ListNode* p = head2; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    head2 = solution.oddEvenList(head2);
    
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
