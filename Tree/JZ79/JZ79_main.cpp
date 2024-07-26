/*
    描述
        输入一棵节点数为 n 二叉树，判断该二叉树是否是平衡二叉树。
        在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
        平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

    测试已通过！

    GPT的意见：
        递归计算深度，重复计算，影响性能。  
        可以使用递归函数同时计算深度和判断平衡：在递归过程中，如果子树不平衡，直接返回 -1，否则返回子树的高度。

    递归计算二叉树深度的核心在于到底端的时候为0，每次递归+1。
    其实calDepth里面已经计算出了当前节点的左右子树的深度，完全可以顺便判断是否差值不符合条件。
    相应地，为calDepth补充差值不符合条件时的返回值和对返回值的判断即可，这就是answer的改进之处。

*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int calDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int ld = calDepth(root->left);
        int rd = calDepth(root->right);
        int depth = (ld > rd) ? ld+1 : rd+1;
        return depth;
    }
    bool Helper(TreeNode* pRoot){
        if(pRoot == nullptr) return true;
        
        if(pRoot->left == nullptr && pRoot->right == nullptr){
            return true;
        }
        else{
            int leftDepth = calDepth(pRoot->left);
            int rightDepth = calDepth(pRoot->right);
            if(leftDepth - rightDepth <= 1 && 
                leftDepth - rightDepth >= -1){
                    return Helper(pRoot->left) && Helper(pRoot->right);
                }
        }
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr) return true;

        return Helper(pRoot);
    }
};