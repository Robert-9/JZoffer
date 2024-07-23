/*
    从尾到头打印链表
    输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值
    用数组返回

    测试未通过
*/
#include <JZ6_headfile.h>
#pragma execution_character_set("utf-8")

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};

class Solution{
public:
    std::vector<int> printListFromTail2Head(ListNode* head){
        /*
            param:   Head node of the list.
            result: Reversed list.
        */
        int lenth = 0;
        ListNode* tempPtr;
        tempPtr = head->next;
        // 读出长度
        while(tempPtr->next!=NULL){
            tempPtr = tempPtr->next;
            lenth++;
        }
        tempPtr = head->next;

        std::vector<int> vec(lenth);
        std::vector<int> re_vec(lenth);

        vec[0] = head->val;
        for(int j=1; j<lenth; j++){
            vec[j] = tempPtr->val;
            tempPtr = tempPtr->next;
        }

        int i = lenth;
        for(int j=0; j<lenth; j++){
            i--;
            re_vec[j] = vec[i];
        }

       return re_vec;
    }
};

int main(int input)
{
    // 初始化
    int array[] = {1, 2, 3};
    int len = sizeof(array);
    ListNode* head = new ListNode(array[0]); 
    ListNode* current = head;

    // 将数组的值提取出来
    for(int i= 0; i<len; i++){
        current->next = new ListNode(array[i]);
        current = current->next;
    }
    current->next = NULL;

    Solution solution;
    std::vector<int> re_arr = solution.printListFromTail2Head(head);
    for(int val : re_arr){
        std::cout << val << ",";
    }
    std::cout << std::endl;
    
    return 0;
}

