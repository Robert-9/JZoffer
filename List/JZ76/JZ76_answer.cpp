/*
    GPT给的答案
    关键点：
        1. 用pPrev pCurr 和 pCurr->next 省了一个后置节点
        2. ***虚拟头节点***
            1) 只有头节点一个节点时，
            2) 头节点也有重复时，
            3) 所有节点均为重复时，
        3. 用 prev->next = current; 删除头节点

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
        if (pHead == nullptr) return nullptr;

        // 创建一个虚拟头节点
        ListNode* dummy = new ListNode(0);  // 使用虚拟头节点 dummy 可以简化对链表头节点的处理，因为头节点可能是重复节点
        dummy->next = pHead;
        
        // prev 初始化为虚拟头节点，current 初始化为链表头节点
        ListNode* prev = dummy;
        ListNode* current = pHead;

        // current为空，则说明prev已经是最后一个值；current->next为空，则说明current是最后一个值。
        // 由于比较的是current及其next，故current为空时就可以退出了。
        while (current != nullptr && current->next != nullptr){  // 检查当前节点和下一个节点是否存在并且是否重复
            if (current->val == current->next->val) {
                int duplicateVal = current->val;
                
                while (current != nullptr && current->val == duplicateVal) {
                    current = current->next;
                }
                prev->next = current;  // 跳过所有重复的节点
            } else {
                // 无重复，移动前驱节点
                prev = current;
                current = current->next;
            }
        }

        // 返回新的链表头节点并释放虚拟头节点的内存
        ListNode* newHead = dummy->next;
        delete dummy;  
        return newHead;

    }
};


