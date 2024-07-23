/*
    "你的解决方案中使用了向量来存储链表的节点值，并通过反转向量来查找第一个不同的节点。虽然这是一个可行的方法，但时间复杂度和空间复杂度都较高。"

    我们可以采用一个更高效的方法来解决这个问题。
    下面是一个优化后的解决方案，使用两个指针遍历链表来找到第一个公共节点：

    该方法的思路是：两个指针分别遍历两个链表，当其中一个指针遍历到链表末尾时，切换到另一个链表的头节点继续遍历。
    这样，当两个指针相遇时即为第一个公共节点。

    双指针法：
        使用两个指针 p1 和 p2，分别从 pHead1 和 pHead2 开始遍历链表。
        当 p1 遍历完 pHead1 时，切换到 pHead2 继续遍历；同样地，当 p2 遍历完 pHead2 时，切换到 pHead1 继续遍历。
        如果两个链表有公共节点，最终 p1 和 p2 会相遇在第一个公共节点；如果没有公共节点，两个指针最终都会遍历到链表的末尾（nullptr），此时返回 nullptr
    优点：
        该方法只需使用常数级别的额外空间。
        时间复杂度为 O(n + m)，其中 n 和 m 分别是两个链表的长度
*/

#include "JZ52_headfile.h"
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        // 空的判断
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }

        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;

        while (p1 != p2) {
            p1 = (p1 == nullptr) ? pHead2 : p1->next;  // condition ? value_if_true : value_if_false;
            p2 = (p2 == nullptr) ? pHead1 : p2->next;
        }

        return p1;
    }
};