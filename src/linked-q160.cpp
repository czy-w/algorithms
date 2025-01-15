// 给定两个链表，判断它们是否相交于一点，并求这个相交节点。
// 注意：
// 1. 如果两个链表没有交点，返回 null
// 2. 在返回结果后，两个链表仍须保持原有的结构
// 3. 可假定整个链表结构中没有循环
// 4. 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存

#include "include/head.h"

// 思路：
// 设链表A的长度为a，链表B的长度为b，公共部分长度为c
// 指针p1走过的路径：a + (b-c)
// 指针p2走过的路径：b + (a-c)
// 因为 a + (b-c) = b + (a-c)，所以两个指针会在相交点相遇
// 如果没有相交点，两个指针会同时到达nullptr

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        // 当ptrA和ptrB相等时退出循环（可能是相交点，也可能是nullptr）
        while (ptrA != ptrB) {
            // 如果到达链表尾部，则转到另一个链表头部
            // 如果没有相交点，最终两个指针都会变成nullptr而相等
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        
        return ptrA;
    }
};

int main() {
    Solution solution;
    
    // 创建测试链表
    // 链表A：4->1->8->4->5
    // 链表B：5->6->1->8->4->5
    // 相交于值为8的节点
    
    Solution::ListNode* commonPart = new Solution::ListNode(8);
    commonPart->next = new Solution::ListNode(4);
    commonPart->next->next = new Solution::ListNode(5);
    
    // 创建链表A
    Solution::ListNode* headA = new Solution::ListNode(4);
    headA->next = new Solution::ListNode(1);
    headA->next->next = commonPart;
    
    // 创建链表B
    Solution::ListNode* headB = new Solution::ListNode(5);
    headB->next = new Solution::ListNode(6);
    headB->next->next = new Solution::ListNode(1);
    headB->next->next->next = commonPart;
    
    // 查找相交节点
    Solution::ListNode* intersection = solution.getIntersectionNode(headA, headB);
    
    // 打印结果
    if (intersection) {
        std::cout << "Intersection node value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection found." << std::endl;
    }
    
    // 清理内存（注意不要重复删除相交部分）
    while (headA != commonPart) {
        Solution::ListNode* temp = headA;
        headA = headA->next;
        delete temp;
    }
    
    while (headB != commonPart) {
        Solution::ListNode* temp = headB;
        headB = headB->next;
        delete temp;
    }
    
    while (commonPart) {
        Solution::ListNode* temp = commonPart;
        commonPart = commonPart->next;
        delete temp;
    }
    
    return 0;
}