#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void calAllPaths(TreeNode* root, int currentSum, int targetSum, int& pathNum) {
        if (root == nullptr) return;

        currentSum += root->val;

        if (currentSum == targetSum) {
            pathNum++;
        }

        calAllPaths(root->left, currentSum, targetSum, pathNum);
        calAllPaths(root->right, currentSum, targetSum, pathNum);
    }

    void Preorder(TreeNode* root, int targetSum, int& pathNum) {
        /*
            遍历根节点的所有子树
        */
        if (root == nullptr) return;

        // 计算以当前节点为起点的所有路径中， 和为targetSum的个数，存在pathNum中
        calAllPaths(root, 0, targetSum, pathNum);

        // 遍历左子树和右子树
        Preorder(root->left, targetSum, pathNum);
        Preorder(root->right, targetSum, pathNum);
    }

public:
    int FindPath(TreeNode* root, int sum) {
        if (root == nullptr) return 0;

        int pathNum = 0;
        Preorder(root, sum, pathNum);

        return pathNum;
    }
};

int main() {
    // 创建一个示例二叉树:
    //         5
    //       /   \
    //      4     8
    //     /     / \
    //    11    13  4
    //   /  \       / \
    //  7    2     5   1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution solution;
    int sum = 22;
    int result = solution.FindPath(root, sum);
    std::cout << "Number of paths with sum " << sum << " is: " << result << std::endl;

    return 0;
}
