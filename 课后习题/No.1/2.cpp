#include <iostream>

struct node {
    int data;
    node* next;
};

node* addTwoNumbers(node* l1, node* l2) {
    node dummy;  // 哑节点简化头节点处理，就可以不用去用new来定义
    node* current = &dummy;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        // 获取当前节点的值（如果存在）
        int val1 = l1 ? l1->data : 0;
        int val2 = l2 ? l2->data : 0;
        
        // 计算和与进位
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        
        // 创建新节点
        // ... 其他代码保持不变 ...

        // 创建新节点的完整过程分解：
        // 1. new操作符在堆内存中分配节点空间
        //node* newNode = new node;  

        // 2. 给节点成员赋值
        //newNode->data = sum % 10;  // 设置数据域
        //newNode->next = nullptr;    // 设置指针域

        // 3. 将新节点链接到链表
        //current->next = newNode;

        // 可以简化为直接初始化版本（代码中原有的写法）：

        current->next = new node{sum % 10, nullptr};
        current = current->next;
        
        // 移动链表指针
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    return dummy.next;
}

// 示例用法（可删除）
int main() {
    // 示例链表1: 342 (2->4->3)
    node* l1 = new node{2, new node{4, new node{3, nullptr}}};
    // 示例链表2: 465 (5->6->4)
    node* l2 = new node{5, new node{6, new node{4, nullptr}}};
    
    node* result = addTwoNumbers(l1, l2);
    
    // 输出结果应为 7->0->8
    while (result) {
        std::cout << result->data << " ";
        result = result->next;
    }
    return 0;
}