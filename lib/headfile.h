#include <vector>
#include <iostream>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// 打印链表
void printList(ListNode* listHead){
    ListNode* current = listHead;
    for (; current != nullptr; )
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    
}


// 初始化
