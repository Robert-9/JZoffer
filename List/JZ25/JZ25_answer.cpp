/*
    相比于自己的做法，GPT提供的做法是
    直接在将链表中的节点读出来的同时，进行了比大小和赋值的操作，
    省略了把所有的值读出来的操作。
 */

#include "JZ25_headfile.h"

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // 先判断空的情况
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;

        // 初始化合并后的链表头节点
        ListNode* mergedHead = nullptr;
        if (pHead1->val < pHead2->val) {
            mergedHead = pHead1;
            pHead1 = pHead1->next;
        } else {
            mergedHead = pHead2;
            pHead2 = pHead2->next;
        }

        ListNode* current = mergedHead;

        // 合并两个链表
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val < pHead2->val) {
                current->next = pHead1;  // current是合并后链表的当前节点
                pHead1 = pHead1->next;  // 此时的pHead充当了对应链表的当前节点，不再只是头节点了
            } else {
                current->next = pHead2;
                pHead2 = pHead2->next;
            }
            current = current->next;
        }

        // 如果有剩余节点，直接连接到合并后的链表末尾
        if (pHead1 != nullptr) {
            current->next = pHead1;
        } else {
            current->next = pHead2;
        }

        return mergedHead;
    }
};

int main() {
    // 创建链表 1 -> 3 -> 5 -> 7
    ListNode* pHead1 = new ListNode(1);
    ListNode* current = pHead1;
    for (int i = 1; i <= 3; ++i) {
        current->next = new ListNode(1 + 2 * i);
        current = current->next;
    }

    // 创建链表 2 -> 4 -> 6 -> 8
    ListNode* pHead2 = new ListNode(2);
    current = pHead2;
    for (int i = 1; i <= 3; ++i) {
        current->next = new ListNode(2 + 2 * i);
        current = current->next;
    }

    // 合并链表
    Solution solution;
    ListNode* mergedHead = solution.Merge(pHead1, pHead2);

    // 打印结果
    current = mergedHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 释放链表内存
    current = mergedHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
