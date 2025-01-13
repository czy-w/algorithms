// 给定一个矩阵，交换每个相邻的一对节点
#include "include/head.h"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head, *s;
        if (p && p->next) {
            s = p->next;
            p->next = s->next;
            s->next = p;
            head = s;
            while (p->next && p->next->next) {
                s = p->next->next;
                p->next->next = s->next;
                s->next = p->next;
                p->next = s;
                p = s->next;
            }
        }
        return head;
    }
};

int main() {
    // 初始化链表节点
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;

    Solution solution;

    // 使用迭代方法反转链表
    ListNode* reversedHead = solution.swapPairs(node1);

    // 打印反转后的链表
    for (ListNode* p = reversedHead; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;

    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}