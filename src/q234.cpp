// 输入是一个链表，输出是一个布尔值，表示链表是否回文。
#include "include/head.h"

// 先使用快慢指针找到链表中点，再把链表切成两半；然后把后半段翻转；最后比较两半是否相等

class Solution {
   public:
    // 主函数
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    // 辅函数
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};