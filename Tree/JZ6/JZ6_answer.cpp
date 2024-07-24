#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next; // 指向父节点的指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeNode* GetNext(TreeNode* pNode) {
        if (pNode == nullptr) return nullptr;

        // 1. 如果节点有右子树，下一个节点是右子树中的最左节点
        if (pNode->right != nullptr) {
            TreeNode* nextNode = pNode->right;
            while (nextNode->left != nullptr) {
                nextNode = nextNode->left;
            }
            return nextNode;
        }

        // 2. 如果节点没有右子树
        while (pNode->next != nullptr) {
            TreeNode* parent = pNode->next;
            if (parent->left == pNode) {
                return parent;
            }
            pNode = parent;
        }

        // 如果没有找到下一个节点，返回nullptr
        return nullptr;
    }
};

int main() {
    // 创建一个示例二叉树:
    //         10
    //       /    \
    //      6      14
    //     / \    /  \
    //    4   8  12  16
    // 测试代码中，每个节点的next指针要正确设置
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);
    root->left->next = root;
    root->right->next = root;
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->left->left->next = root->left;
    root->left->right->next = root->left;
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);
    root->right->left->next = root->right;
    root->right->right->next = root->right;

    Solution solution;
    TreeNode* nextNode = solution.GetNext(root->left); // 找节点 6 的下一个节点

    if (nextNode != nullptr) {
        std::cout << "The next node of " << root->left->val << " is " << nextNode->val << std::endl;
    } else {
        std::cout << "The next node of " << root->left->val << " is nullptr" << std::endl;
    }

    // 清理内存
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
