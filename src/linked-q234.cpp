// 给定一个单链表，判断它是否为回文链表
// 例如：
// 1->2->2->1 是回文链表
// 1->2->3->2->1 是回文链表
// 1->2->3->1 不是回文链表

#include "include/head.h"

// 思路：
// 1 使用快慢指针找到链表中点：
// 快指针每次移动两步
// 慢指针每次移动一步
// 当快指针到达末尾时，慢指针指向中点
// 2 反转后半部分链表：
// 使用三个指针（prev、curr、next）进行链表反转
// 反转后半部分链表，使其方向与前半部分相同
// 3 比较前后两部分是否相同：
// 从头节点和反转后的后半部分开始比较
// 如果所有节点值都相同，则是回文链表
// 4 恢复链表（可选）：
// 将后半部分再次反转，恢复原始链表结构
// 时间复杂度O(n)，空间复杂度O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 1. 找到中点
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. 反转后半部分
        ListNode* secondHalf = reverseList(slow->next);
        
        // 3. 比较前后两部分
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf; // 保存反转后的头节点，用于后面恢复链表
        bool isPalind = true;
        
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                isPalind = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        // 4. 恢复链表（可选）
        slow->next = reverseList(temp);
        
        return isPalind;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1：1->2->2->1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);
    
    std::cout << "Test case 1 (1->2->2->1): " 
              << (solution.isPalindrome(head1) ? "Is palindrome" : "Not palindrome") 
              << std::endl;
    
    // 测试用例2：1->2->3->2->1
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(2);
    head2->next->next->next->next = new ListNode(1);
    
    std::cout << "Test case 2 (1->2->3->2->1): " 
              << (solution.isPalindrome(head2) ? "Is palindrome" : "Not palindrome") 
              << std::endl;
    
    // 测试用例3：1->2->3->1
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(1);
    
    std::cout << "Test case 3 (1->2->3->1): " 
              << (solution.isPalindrome(head3) ? "Is palindrome" : "Not palindrome") 
              << std::endl;
    
    // 清理内存
    ListNode* curr;
    
    curr = head1;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    curr = head2;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    curr = head3;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    return 0;
}