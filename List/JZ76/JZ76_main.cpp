/*
    描述
    在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
    例如，链表 1->2->3->3->4->4->5  处理后为 1->2->5
    注意它是全删掉了

    一开始没做出来！！
    对于删除节点还想得不太清楚
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
    ListNode* deleteDuplication(ListNode* pHead) {
        // 空的判断
        if(pHead == nullptr) return nullptr;

        // 先考虑小于等于3个节点的情况 

        // 三个指针 一前置一现在一后置 现在和后置相同则进入循环
        ListNode* pPrev = pHead;
        ListNode* pCurr = pHead->next;
        ListNode* pNext = pHead->next->next;

        while(pNext != nullptr){
            if(pCurr->val == pNext->val){  // 相等 则先移动到不相等，再删掉所有对应val的节点
                while (pCurr->val == pNext->val){
                    if (pNext->next != nullptr){
                        pNext = pNext->next;
                    }
                    else{
                        operateInputList(pHead, pCurr->val);
                        break;
                    }
                }
                
                pCurr = pCurr->next;
                pNext = pNext->next;
                operateInputList(pHead, pCurr->val);
            }
            else{ // 不相等 则移动所有指针
                pPrev = pPrev->next;
                pCurr = pCurr->next;
                pNext = pNext->next;
            }
            
        }
    }
private:
    void operateInputList(ListNode* pHead, int value){
        /*
            从链表中删除对应值的节点
            @param: pHead: 头节点
                    value: 要删除的节点对应的值
            @note: 输入的链表是顺序的
        */
        ListNode* pCurr = pHead;
        ListNode* pDelete = pHead->next;
        while(pDelete != nullptr){
            if(pDelete->val == value){
                pCurr->next = pDelete->next;
                pDelete = pCurr->next->next;
                break;
            }
            else{
                pCurr = pCurr->next;
                pDelete = pDelete->next;
            }
            
        }
    }
};