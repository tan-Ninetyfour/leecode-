struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 迭代法实现
ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    
    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = first->next;
        
        // 执行交换操作
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        // 移动指针到下一组的前驱位置
        prev = first;
    }
    return dummy.next;
}

// 递归法实现（可作为替代方案）
/*
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    
    return newHead;
}
*/