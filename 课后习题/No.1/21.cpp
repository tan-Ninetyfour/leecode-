// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 创建虚拟头节点简化操作
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // 交替连接较小值的节点
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        // 连接剩余节点
        current->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};