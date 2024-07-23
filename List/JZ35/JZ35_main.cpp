/*
    输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点）
    请对此链表进行深拷贝，并返回拷贝后的头结点。

    测试已通过 一遍过
 */

#include <iostream>

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        // 空的判断
        if (pHead == nullptr)
            return nullptr;

        int listLen;
        RandomListNode *pReHead = new RandomListNode(pHead->label);
        RandomListNode *pInCurr = pHead;
        RandomListNode *pReCurr = pReHead;

        // 先复制主干next 上的
        pInCurr = pInCurr->next;
        for (listLen = 0; pInCurr != nullptr; listLen++){
            pReCurr->next = new RandomListNode(pInCurr->label);
            pInCurr = pInCurr->next;
            pReCurr = pReCurr->next;
        }

        // 再复制跳跃的
        int value;
        pInCurr = pHead;
        pReCurr = pReHead;
        RandomListNode *pReScan = pReHead;
        
        for(int i=0; i<listLen ; i++ ){
            if(pInCurr->random != nullptr){
                // 将输出的扫描指针归位
                pReScan = pReHead;
                // 提取出对应节点的值                
                value = pInCurr->random->label;
                for(; pReScan != nullptr;){
                    if(pReScan->label == value){
                        pReCurr->random = pReScan;
                    }
                    pReScan = pReScan->next;
                }
                 
            }
            pInCurr = pInCurr->next;
            pReCurr = pReCurr->next;
        }
        return pReHead;
    }
};

int main(int argc, char const *argv[])
{
    // 创建复杂链表 { 1,2,3,4,5, 3,5,#,2,# }
    RandomListNode *pHead = new RandomListNode(1);
    RandomListNode *pTemp = pHead;
    for (int i = 2; i <= 5; i++)
    {
        pTemp->next = new RandomListNode(i);
    }
    pHead->random = pHead->next->next;                   // 1-3
    pHead->next->random = pHead->next->next->next->next; // 2-5
    pHead->next->next->next->random = pHead->next;       // 4-2
    // 调用方法
    Solution solution;
    RandomListNode *pReturn = solution.Clone(pHead);

    std::cout << "Returned head node: " << pReturn->label;
    return 0;
}
