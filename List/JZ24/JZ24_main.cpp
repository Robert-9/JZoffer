/*
    题目：
        描述：给定一个单链表的头结点pHead(该头节点是有值的)，长度为n，反转该链表后，返回新链表的表头。
        数据范围： 0≤𝑛≤1000
        要求：空间复杂度 𝑂(1)，时间复杂度 𝑂(𝑛)。
        如当输入链表{1,2,3}时，经反转后，原链表变为{3,2,1}，所以对应的输出为{3,2,1}。
    思路：
        1、按顺序读取链表中的元素到数组；
        2、按倒序将数组中的元素赋值给链表，覆盖原值。

    测试已通过
*/

#include "JZ24_headfile.h"
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    // ListNode* ReverseList(ListNode* head) {
    //     // 初始化变量
    //     int count;
    //     std::vector<int> vec;
    //     ListNode* current = head;

    //     ListNode* return_head = new ListNode(head->val);
    //     // current->next = head->next;

    //     // 将链表节点值存储到 vector 中
    //     // for(count = 0; current->next != nullptr; count++){
    //     for(count = 0; current != nullptr; count++){
    //         vec.push_back(current->val);
    //         current = current->next;
    //     }
    //     // vec.push_back(current->val);

    //     std::reverse(vec.begin(), vec.end());

    //     // 创建新的反转后的链表
    //     return_head->val = current->val;
    //     return_head->next = current->next;
    //     // count-=1;
    //     for(int j=0; j<vec.size(); j++){
    //         current->val = vec[j];
    //         current = current->next;
    //     }
    //     return return_head;
    // }

    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        // 初始化变量
        int count;
        std::vector<int> vec;
        ListNode* current = head;

        for(count = 0; current != nullptr; count++){
            vec.push_back(current->val);
            current = current->next;
        }

        std::reverse(vec.begin(), vec.end());

        // 创建新的反转后的链表
        ListNode* return_head = new ListNode(vec[0]);
        current = return_head;
        for(int j=1; j<vec.size(); j++){
            current->next = new ListNode(vec[j]);
            current = current->next;
        }
        return return_head;
    };

};


int main()
{
    Solution solution;

    ListNode* pHead = new ListNode(1);
    ListNode* current = pHead;
    for(int i=2; i<=7; i++){
        current->next = new ListNode(i);  // current->next和pHead->next是相同的，这样就实现了关联
        current = current->next;
    }

    // 测试输入
    ListNode* returnedPtr = solution.ReverseList(pHead);
    // 打印结果
    for(;returnedPtr != nullptr;){
        std::cout << returnedPtr->val << "";
        returnedPtr = returnedPtr->next;
    }
    return 0;
}
