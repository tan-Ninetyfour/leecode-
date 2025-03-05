#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // 哑节点简化头节点处理
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // 快指针先走n+1步（包含哑节点）
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // 同时移动快慢指针直到链表末尾
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 删除目标节点
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        ListNode* newHead = dummy->next;
        delete dummy; // 释放哑节点内存
        return newHead;
    }
};

// 测试代码需要自行添加