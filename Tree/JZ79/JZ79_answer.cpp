#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // 辅助函数：递归计算树的高度，如果不平衡返回-1
    int Helper(TreeNode* root) {
        if (root == nullptr) return 0; // 空树高度为0

        int leftHeight = Helper(root->left);
        if (leftHeight == -1) return -1; // 左子树不平衡

        int rightHeight = Helper(root->right);
        if (rightHeight == -1) return -1; // 右子树不平衡

        if (std::abs(leftHeight - rightHeight) > 1) return -1; // 当前节点不平衡

        return std::max(leftHeight, rightHeight) + 1; // 返回树的高度
    }

public:
    // 主函数：判断二叉树是否平衡
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return Helper(pRoot) != -1; // 判断辅助函数的返回值是否为-1
    }
};

int main() {
    // 测试代码
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    bool result = solution.IsBalanced_Solution(root);
    std::cout << (result ? "True" : "False") << std::endl;

    // 清理内存
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
