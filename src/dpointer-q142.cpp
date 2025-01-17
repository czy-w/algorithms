// 给定一个链表，如果有环路，找出环路的开始点。

#include "include/head.h"

// 第一步：使用快慢指针检测是否存在环
// 慢指针每次移动一步
// 快指针每次移动两步
// 如果存在环，两个指针最终会在环中某个节点相遇
// 第二步：找到环的入口点
// 将慢指针重新指向头节点
// 快指针保持在相遇点
// 两个指针都以相同速度（每次一步）移动
// 两个指针相遇的点就是环的入口点

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        
        // 第一步：使用快慢指针检测是否存在环
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        
        // 如果没有环，直接返回nullptr
        if (!hasCycle) {
            return nullptr;
        }
        
        // 第二步：找到环的入口点
        // 将一个指针重新指向头节点，另一个指针保持在相遇点
        // 两个指针以相同速度移动，相遇点即为环的入口
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

// 用于测试的辅助函数：创建带环的链表
ListNode* createCyclicList(const std::vector<int>& values, int pos) {
    if (values.empty()) return nullptr;
    
    // 创建链表
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (static_cast<int>(i) == pos) {
            cycleNode = current;
        }
    }
    
    // 如果需要创建环，将最后一个节点指向指定位置
    if (pos >= 0) {
        current->next = cycleNode;
    }
    
    return head;
}

int main() {
    // 创建测试用例：1->2->3->4->5->2（环从2开始）
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createCyclicList(values, 1);  // pos=1表示环从第二个节点开始
    
    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);
    
    if (cycleStart) {
        std::cout << "环的起始节点值为: " << cycleStart->val << std::endl;
    } else {
        std::cout << "链表中没有环" << std::endl;
    }
    
    return 0;
}