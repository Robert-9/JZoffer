/*
    测试已通过
 */

#include "JZ24_headfile.h"


// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        // 初始化变量
        std::vector<int> vec;
        ListNode* current = head;

        // 将链表节点值存储到 vector 中
        while (current != nullptr) {
            vec.push_back(current->val);
            current = current->next;
        }

        // 创建新的反转后的链表
        ListNode* newHead = new ListNode(vec.back());  // vec.back() 返回 vec 向量中最后一个元素的值。
        current = newHead;
        for (int i = vec.size() - 2; i >= 0; --i) {
            current->next = new ListNode(vec[i]);
            current = current->next;
        }

        return newHead;
    }
};

int main() {
    // 创建链表 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    ListNode* pHead = new ListNode(1);
    ListNode* current = pHead;
    for (int i = 2; i <= 7; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }

    // 反转链表
    Solution solution;
    ListNode* returnedPtr = solution.ReverseList(pHead);

    // 打印结果
    current = returnedPtr;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 释放链表内存
    current = returnedPtr;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
