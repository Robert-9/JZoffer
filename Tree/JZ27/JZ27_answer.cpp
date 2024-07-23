#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void Exchange(TreeNode* pRoot){
        if(pRoot == nullptr) return;

        // 先递归遍历左子树和右子树
        Exchange(pRoot->left);
        Exchange(pRoot->right);

        // 然后交换左右子树
        TreeNode* tempNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tempNode;
    }

public:
    TreeNode* Mirror(TreeNode* pRoot){
        Exchange(pRoot);
        return pRoot;
    }
};

// Helper function to print the tree level by level (for testing)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << node->val << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    std::cout << std::endl;
}

int main() {
    // Create a test tree: 
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    solution.Mirror(root);

    // Print the mirrored tree: should be
    //      1
    //     / \
    //    3   2
    //       / \
    //      5   4
    printTree(root);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
