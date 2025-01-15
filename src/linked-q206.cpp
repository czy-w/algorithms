// 206 翻转一个链表

#include "include/head.h"

// 定义ListNode结构体
class Solution {
   public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    // 递归法
    // 基本情况：如果头节点为空，返回前一个节点
    // 保存下一个节点
    // 将当前节点指向前一个节点
    // 递归处理下一个节点，并将当前节点作为新的前一个节点
    ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        if (!head) {
            return prev;
        }
        ListNode* next = head->next;
        head->next = prev;
        return reverseList(next, head);
    }

    // 迭代法
    // 基本情况：如果头节点为空，返回前一个节点
    // 保存下一个节点
    // 将当前节点指向前一个节点
    // 递归处理下一个节点，并将当前节点作为新的前一个节点
    ListNode* reverseListIterative(ListNode* head) {
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

int main() {
    // 初始化链表节点
    Solution::ListNode* node1 = new Solution::ListNode(1);
    Solution::ListNode* node2 = new Solution::ListNode(2);
    Solution::ListNode* node3 = new Solution::ListNode(3);
    node1->next = node2;
    node2->next = node3;

    Solution solution;

    // 使用迭代方法反转链表
    Solution::ListNode* reversedHead = solution.reverseListIterative(node1);

    // 打印反转后的链表
    for (Solution::ListNode* p = reversedHead; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;

    while (reversedHead != nullptr) {
        Solution::ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    std::cout << " Press Enter to exit... " << std::endl;
    std::cin.get();

    return 0;
}