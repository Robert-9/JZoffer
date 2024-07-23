#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        // 基础条件检查，空树不是任何树的子结构
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        
        // 如果根节点值相等，检查子树是否相等
        if (pRoot1->val == pRoot2->val && isSubtree(pRoot1, pRoot2)) {
            return true;
        }
        
        // 递归检查左子树和右子树
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

private:
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        // 子树检查的结束条件
        if (pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr || pRoot1->val != pRoot2->val) {
            return false;
        }
        
        // 递归检查左右子树
        return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
    }
};

int main() {
    // 创建树 A
    TreeNode* A = new TreeNode(8);
    A->left = new TreeNode(8);
    A->right = new TreeNode(7);
    A->left->left = new TreeNode(9);
    A->left->right = new TreeNode(2);
    A->left->right->left = new TreeNode(4);
    A->left->right->right = new TreeNode(7);

    // 创建树 B
    TreeNode* B = new TreeNode(8);
    B->left = new TreeNode(9);
    B->right = new TreeNode(2);

    Solution solution;
    bool result = solution.HasSubtree(A, B);

    if (result) {
        std::cout << "Tree B is a subtree of Tree A" << std::endl;
    } else {
        std::cout << "Tree B is not a subtree of Tree A" << std::endl;
    }

    // 释放内存
    delete A->left->right->right;
    delete A->left->right->left;
    delete A->left->right;
    delete A->left->left;
    delete A->left;
    delete A->right;
    delete A;
    delete B->left;
    delete B->right;
    delete B;

    return 0;
}
