/*
    描述:
        给一个长度为n链表，若其中包含环，请找出该链表的环的入口结点，否则，返回null。
*/

#include "JZ23_headfile.h"


class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        // 空的情况
        if(pHead == nullptr) return nullptr;

        // 双指针法 快慢指针
        ListNode* pSlow = pHead;
        ListNode* pFast = pHead;
        while(pFast != nullptr){  //有一个为空则说明无环了

            // 移动不同的长度
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if(pFast == nullptr || pSlow == nullptr){
                break;
            }

            // 有环的话快指针会追上慢指针
            if(pSlow == pFast){
                // 追上了 开始找环的入口
                pSlow = pHead;
                while (pSlow != pFast){
                    pSlow = pSlow->next;
                    pFast = pFast->next;
                }
                return pSlow;
            }
        }
        return nullptr;

    }
};


int main()
{
    // 创建一个有环的链表: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (环)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // 5 -> 3 (创建环)

    Solution solution;
    ListNode* pReturn = solution.EntryNodeOfLoop(head);
    std::cout<<"pReturn = "<< pReturn->val<< " ";

    return 0;
}
