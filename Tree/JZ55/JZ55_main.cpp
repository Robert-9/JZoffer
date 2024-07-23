/*
    描述：
        输入一棵二叉树，求该树的深度。
        从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度，根节点的深度视为 1

    测试已通过
    用递归的方法计算树的深度
*/
#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return 0;
        } else {
            int leftDepth = TreeDepth(pRoot->left);
            int rightDepth = TreeDepth(pRoot->right);
            return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    // 创建二叉树


    return 0;
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    Solution solution;
    int depth = solution.TreeDepth(root);
    std::cout << "二叉树的深度是: " << depth;  // 输出: 二叉树的深度是: 4

    // 释放内存
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}