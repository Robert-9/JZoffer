#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* prevNode = nullptr; // 记录前一个处理的节点

    void Inorder(TreeNode* root, TreeNode*& head) {
        if (root == nullptr) return;

        // 递归遍历左子树
        Inorder(root->left, head);

        // 处理当前节点
        if (prevNode == nullptr) {  // prevNode未被赋值，说明 当前节点是最左节点，也是双向链表的头节点
            head = root;
        } 
        else {  // 互相指
            prevNode->right = root;
            root->left = prevNode;
        }
        // 更新节点
        prevNode = root;

        // 递归遍历右子树
        Inorder(root->right, head);
    }

public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;

        TreeNode* head = nullptr;
        Inorder(pRootOfTree, head);
        return head;
    }
};

// Helper function to print the double linked list
void printList(TreeNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

int main() {
    // 创建一个示例二叉搜索树: 
    //      4
    //     / \
    //    2   5
    //   / \
    //  1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    TreeNode* head = solution.Convert(root);

    // 输出双向链表
    printList(head);

    // 清理内存
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
