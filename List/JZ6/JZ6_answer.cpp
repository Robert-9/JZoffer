/*
    测试已通过
    整体思路为：
    1、遍历链表，提取每一个值到向量中；
    2、将向量倒序。
    3、注意有一个测试输入为：输入空链表，返回也应该是空数组。如果不加对 空 情况的判断，则无返回，导致无法通过。故增加了单独的判断。
*/

#include <JZ6_headfile.h>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
  public:
    std::vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* tempPtr = head;
        std::vector<int> vec;
        if(tempPtr == NULL){
            return vec;
        }
        
        while(tempPtr->next != NULL){
            vec.push_back(tempPtr->val);
            tempPtr = tempPtr->next;
        }
        vec.push_back(tempPtr->val);
        std::reverse(vec.begin(), vec.end());

        return vec;
    }

};


