#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        
        while (true) {
            // 定位当前组的起点和终点
            ListNode* start = pre->next;
            ListNode* end = pre;
            
            // 检测剩余节点是否足够k个
            for (int i = 0; i < k; ++i) {
                end = end->next;
                if (!end) return dummy.next;
            }
            
            // 保存下一组起点并断开当前组
            ListNode* next_group = end->next;
            end->next = nullptr;
            
            // 翻转当前组并连接
            pre->next = reverseList(start);
            start->next = next_group;
            
            // 移动pre指针到当前组的新结尾
            pre = start;
        }
    }

private:
    // 翻转链表辅助函数
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// 测试代码（使用时需要自行添加链表打印和释放逻辑）