/*
    描述
        操作给定的二叉树，将其变换为源二叉树的镜像。

    测试通过！
    GPT给出的意见：
        冗余判断：
            在交换左右子树时，已经有递归调用遍历左右子树，额外判断左右子树是否为空没有必要。
        交换逻辑问题：
            代码中对左右子树的交换逻辑有点复杂，可以通过简单交换来处理。
        返回值的问题：
            递归函数 Exchange 的返回值实际没有被利用，可以简化。
        具体修改详见answer
*/
#include <vector>
#include <iostream>
#include <stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution
{
private:
    TreeNode* Exchange(TreeNode* pRoot){
        if(pRoot == nullptr) return pRoot;

        Exchange(pRoot->left);
        Exchange(pRoot->right);

        TreeNode* tempNode;
        if(pRoot->left == nullptr){
            pRoot->left = pRoot->right;
            pRoot->right = nullptr;
        }
        else if(pRoot->right == nullptr){
            pRoot->right = pRoot->left;
            pRoot->left = nullptr;
        }
        else{
            tempNode = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tempNode;
        }

        return pRoot;
    }
public:
    TreeNode* Mirror(TreeNode* pRoot){
        if(pRoot == nullptr) return nullptr;

        Exchange(pRoot);

        return pRoot;
    }
};

