#include <vector>
#include <iostream>
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void get_inputs(std::vector<int> arr1, std::vector<int> arr2, std::vector<int> arr3, ListNode* pHead1, ListNode* pHead2);