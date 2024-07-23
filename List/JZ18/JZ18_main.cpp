/*
    描述
        给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
        题目保证链表中节点的值互不相同

        测试已通过，思路同JZ76
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        
        // 创建一个虚拟头节点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pCurr = head;
        ListNode* pPrev = dummy;

        while(pCurr->next != nullptr && pCurr != nullptr){
            if(pCurr->val == val){
                pPrev->next = pCurr->next;
                pCurr = pPrev->next;
            }
            else{
                pCurr = pCurr->next;
                pPrev = pPrev->next;
            }
        }
        // 返回新的头节点
        ListNode* newHead = dummy->next;
        return newHead;
    }
};