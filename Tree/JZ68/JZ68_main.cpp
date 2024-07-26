/*
    描述
        给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

    本题和JZ86 给定一个普通二叉树找公共祖先是一样的，但可通过二叉搜索树的性质简化查找过程。
*/

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode*resultNode;

    TreeNode* findLCA(TreeNode* root, int p, int q){
        if(root == nullptr) return root;

        if(p > root->val && q > root->val){
            resultNode = findLCA(root->right, p, q);
        }
        else if(p < root->val && q < root->val){
            resultNode = findLCA(root->left, p, q);
        }
        else{
            resultNode = root;
        }
        return resultNode;
    }
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        int result = findLCA(root, p, q)->val;
        return result;
    }
};


int main() {
    // 创建一个示例二叉树:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(1);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    Solution solution;
    int LCA = solution.lowestCommonAncestor(root, 12, 11);

    std::cout << "LCA is: " << LCA << std::endl;


    return 0;
}