/*
    描述:
        输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
        数据范围： 
        0≤n≤1000，
        −1000≤节点值≤1000
        要求：空间复杂度 O(1)，时间复杂度 O(n)
        如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6}，

        测试已通过！
*/
#include "JZ25_headfile.h"
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // 先判断空的情况
        if(pHead1 == nullptr || pHead2 == nullptr){
            if(pHead1 == nullptr){
                if(pHead2 == nullptr) 
                    return nullptr;
                else return pHead2;
            }
            if(pHead2 == nullptr){
                return pHead1;
            }
        }

        // 初始化相关参数
        std::vector<int> vec1;
        std::vector<int> vec2;
        ListNode* current = pHead1;

        // 提取pHead1中的值
        for (; current != nullptr; )
        {
            vec1.push_back(current->val);
            current = current->next;
        }
        // 提取pHead2中的值
        current = pHead2;
        for (; current != nullptr; )
        {
            vec2.push_back(current->val);
            current = current->next;
        }
        
        int vec1Counter=0, vec2Counter = 0;
        std::vector<int> sumVec;
        
        // 比大小后，将小的送入returnVec
        while(vec1Counter < vec1.size() && vec2Counter < vec2.size()){
            if(vec1[vec1Counter] > vec2[vec2Counter]){
                sumVec.push_back(vec2[vec2Counter]);
                vec2Counter++;
            }
            else{
                sumVec.push_back(vec1[vec1Counter]);
                vec1Counter++;
            }
        }
        // 至少有一个向量已经送完，将为送完向量的剩余值送入returnVec
        if(vec1Counter >= vec1.size()){  // vec1的已经送完
            for (; vec2Counter<vec2.size(); vec2Counter++)
            {
                sumVec.push_back(vec2[vec2Counter]);
            }
            
        }
        else if(vec2Counter >= vec2.size()){  // vec2的已经送完
            for (; vec1Counter<vec1.size(); vec1Counter++)
            {
                sumVec.push_back(vec1[vec1Counter]);
            }
        }

        ListNode* returnHead = new ListNode(sumVec[0]);
        current = returnHead;
        for(int j=1; j<sumVec.size(); j++){
            current->next = new ListNode(sumVec[j]);
            current = current->next;
        }
        // printf("sumVec.size() = %d", int(sumVec.size()));
        return returnHead;
    }
};


int main(int argc, char const *argv[])
{
    
    ListNode* pHead1 = new ListNode(1);
    ListNode* pHead2 = new ListNode(2);

    ListNode* current = pHead1;
    for (int i = 1; i <= 3; i++)
    {
        current->next = new ListNode(1+2*i);
        current = current->next;
    }
    current = pHead2;
    for (int i = 1; i <= 3; i++)
    {
        current->next = new ListNode(2+2*i);
        current = current->next;
    }    


    Solution solution;
    ListNode* returnPtr= solution.Merge(pHead1, pHead2);

    current = returnPtr;
    for (size_t i = 0; i < 8; i++)
    {
        std::cout << current->val;
        current = current->next;
    }
    
    return 0;
}
