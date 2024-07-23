/*
    描述：
        输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
        如果该链表长度小于k，请返回一个长度为 0 的链表。
*/

#include <iostream>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // 空的判断
        if (pHead == nullptr) return nullptr;
        
        // 两个指针
        ListNode* prev = pHead;
        ListNode* current = pHead;
        for(int i=0; i<k; i++){
            prev = prev->next;
            if(prev == nullptr){  // 输入的链表长度小于指定的节点个数
                return nullptr;
            }
        }
        for (; prev != nullptr; )
        {
            prev = prev->next;
            current = current->next;
        }
        return current;

    }
};

int main(int argc, char const *argv[])
{
    ListNode* pHead = new ListNode(1);
    ListNode* pTemp = pHead;
    for (int i = 1; i <= 7; i++)
    {
        pTemp->next = new ListNode(1+i);
        pTemp = pTemp->next;
    }

    Solution solution;
    ListNode* pReturn = solution.FindKthToTail(pHead, 3);
    std::cout<< "pReturn = " << pReturn->val;
    return 0;
}
