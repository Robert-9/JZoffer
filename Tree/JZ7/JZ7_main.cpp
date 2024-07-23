/*
    描述
        给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。

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
    TreeNode* reConstructBinaryTree(std::vector<int>& preOrder, std::vector<int>& vinOrder) {
        if (preOrder.empty() || vinOrder.empty()) return nullptr;
        
        //前序的第一个是根节点
        int rootVal = preOrder[0];
        TreeNode* pRoot = new TreeNode(rootVal);

        // 在中序遍历中找到根节点的位置
        auto it = std::find(vinOrder.begin(), vinOrder.end(), rootVal);
        int rootIndex = it - vinOrder.begin();

        // 构建左子树的前序和中序遍历序列
        std::vector<int> leftPreOrder(preOrder.begin() + 1, preOrder.begin() + 1 + rootIndex);
        std::vector<int> leftVinOrder(vinOrder.begin(), vinOrder.begin() + rootIndex);

        // 构建右子树的前序和中序遍历序列
        std::vector<int> rightPreOrder(preOrder.begin() + 1 + rootIndex, preOrder.end());
        std::vector<int> rightVinOrder(vinOrder.begin() + rootIndex + 1, vinOrder.end());

        // 递归构建左右子树
        pRoot->left = reConstructBinaryTree(leftPreOrder, leftVinOrder);
        pRoot->right = reConstructBinaryTree(rightPreOrder, rightVinOrder);

        return pRoot;

        // for(int i=0; i<vinOrder.size(); i++){
        //     if(vinOrder[i] == rootVal){  // 以根节点为界，区分左右子树
        //         if(i-1 >= 0 ){  // 左子树的界
        //             std::vector<int> leftSubtreePreOrder = ;  // 取出左右子树的前序和中序遍历用于递归
        //             std::vector<int> leftSubtreeVinOrder = ;
        //             pRoot->left = reConstructBinaryTree(leftSubtreePreOrder, leftSubtreeVinOrder);
        //         }
        //         else if(i+1 < vinOrder.size()){ // 右子树的边界
        //             std::vector<int> rightSubtreePreOrder = ;
        //             std::vector<int> rightSubtreeVinOrder = ;                   
        //             pRoot->right = reConstructBinaryTree(rightSubtreePreOrder, rightSubtreeVinOrder);
        //         }
        //         else{
        //             return nullptr;
        //         }
        //         break;
        //     }
        // }
        // return pRoot;
    }
};


void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    std::vector<int> preOrder = {1,2,4,7,3,5,6,8};
    std::vector<int> vinOrder = {4,7,2,1,5,3,8,6};

    Solution solution;
    TreeNode* root = solution.reConstructBinaryTree(preOrder, vinOrder);

    std::cout << "Inorder traversal of the constructed tree is: ";
    printInorder(root);
    std::cout << std::endl;

    return 0;
}

