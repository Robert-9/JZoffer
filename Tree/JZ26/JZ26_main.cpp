/*
    描述
        输入两棵二叉树A，B，判断B是不是A的子结构。（我们约定空树不是任意一个树的子结构）

    GPT给的答案

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
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        // 判断空树的情况
        if(pRoot1 == nullptr || pRoot2 == nullptr){
            return false;
        }

        if(pRoot1 == nullptr){
            return false;
        }
        else if(pRoot2 == nullptr){
            return true;
        }
        // 如果 A 的当前节点值与 B 的根节点值相等，检查 以A的当前节点为根的子树是否包含 B。
        // 如果 A 的当前节点值不等于 B 的根节点值，递归检查A的左子树和右子树是否包含 B。
        if(pRoot1->val == pRoot2->val){
            // 根节点相等，判断左子树是否相等
            HasSubtree(pRoot1->left, pRoot2->left);
            // 判断右子树是否相等
            HasSubtree(pRoot1->right, pRoot2->right);
        }
        // 根节点不相等，判断


    }
};