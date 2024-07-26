#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> Print(TreeNode* pRoot) {
        std::vector<std::vector<int>> resultVec;
        if (pRoot == nullptr) return resultVec;

        std::queue<TreeNode*> q;
        q.push(pRoot);

        while (!q.empty()) {
            int nodeCount = q.size(); // 每一层的节点数
            std::vector<int> valVec;

            for (int i = 0; i < nodeCount; i++) {
                TreeNode* current = q.front();
                q.pop();
                valVec.push_back(current->val);

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            resultVec.push_back(valVec);
        }

        return resultVec;
    }
};

int main() {
    // 创建一个示例二叉树:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    std::vector<std::vector<int>> result = solution.Print(root);

    // 输出结果
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
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
