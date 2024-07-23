/*
    描述:
        输入两个无环的单向链表，找出它们的第一个公共结点，如果没有公共节点则返回空。
        （注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
    示例1：
        输入：{1,2,3},{4,5},{6,7}
        返回值：{6,7}
        说明：
        第一个参数{1,2,3}代表是第一个链表非公共部分，第二个参数{4,5}代表是第二个链表非公共部分，最后的{6,7}表示的是2个链表的公共部分
        这3个参数最后在后台会组装成为2个两个无环的单链表，且是有公共节点的 
    示例2：
        输入：{1},{2,3},{}
        返回值：{}
        说明：2个链表没有公共节点 ,返回null，后台打印{} 
*/
#include "JZ52_headfile.h"
// #include "headfile.h"


class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
        /*
            将两个输入的链表倒序，比较，第一个值不相同的节点的next就是第一个公共节点
        */

        // 空的判断
        if(pHead1 == nullptr || pHead2 == nullptr){
            return nullptr;
        }

        std::vector<int> vec1;
        std::vector<int> vec2;
        ListNode* pIndex = pHead1;

        for (int i = 0; pIndex != nullptr; i++){
            vec1.push_back(pIndex->val);
            pIndex = pIndex->next;
        }
        pIndex = pHead2;
        for (int j = 0; pIndex != nullptr; j++){
            vec2.push_back(pIndex->val);
            pIndex = pIndex->next;
        }        
        
        int count = 0;
        std::reverse(vec1.begin(), vec1.end());
        std::reverse(vec2.begin(), vec2.end());
        if(vec1.size() < vec2.size()){  // 取小的，把小的比完了还没有重复的
            count = vec1.size();
        }
        else{
            count = vec2.size();
        }

        for (int k = 0; k < count; k++)
        {
            if(vec1[k] != vec2[k]){
                // 找到了倒序不同的节点  此时的count还未++
                pIndex = pHead1;
                for (int i = 0; i < vec1.size()-k; i++)
                {
                    pIndex = pIndex->next;
                }
                
                ListNode* commonNode = pIndex;
                return commonNode;
            }
        }

        // 运行到了这里说明 至少有一个链表已经遍历完了，但仍没有找到不同的节点。说明二者是包含关系，应该返回整个短的链表
        if(vec1.size() < vec2.size()){
            return pHead1;
        }
        else return pHead2;
    }

};

void get_inputs(std::vector<int> arr1, std::vector<int> arr2, std::vector<int> arr3, ListNode* pHead1, ListNode* pHead2){
    ListNode* current = pHead1;
    for (int i = 1; i < arr1.size(); i++)
    {
        current->next = new ListNode(arr1[i]);
        current = current->next;
    }
    for (int j = 0; j < arr3.size(); j++)
    {
        current->next = new ListNode(arr3[j]);
        current = current->next;
    }
    
    current = pHead2;
    for (int i = 1; i < arr2.size(); i++)
    {
        current->next = new ListNode(arr2[i]);  // 一开始用的 current = new ListNode(arr2[i]);  导致错误：pHead均没有将arr3接上
        current = current->next;
    }
    for (int j = 0; j < arr3.size(); j++)
    {
        current->next = new ListNode(arr3[j]);
        current = current->next;
    }
}

int main()
{
    // 生成输入参数
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {4, 5, 6};
    std::vector<int> arr3 = {7, 8, 9, 0};
    ListNode* pHead1 = new ListNode(arr1[0]);
    ListNode* pHead2 = new ListNode(arr2[0]);

    get_inputs(arr1, arr2, arr3, pHead1, pHead2);
    
    ListNode* pTemp = pHead2;
    // std::cout << "pHead2: ";
    // for (; pTemp != nullptr;)
    // {
    //     std::cout << pTemp->val << " "; 
    //     pTemp = pTemp->next;
    // }
    
    // 初始化
    Solution solution;
    ListNode* resultPtr = solution.FindFirstCommonNode(pHead1, pHead2);
    std::cout << "resultPtr = ";
    // printList(resultPtr);
    return 0;
}
