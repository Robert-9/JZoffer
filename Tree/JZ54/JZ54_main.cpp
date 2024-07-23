/*
    描述
        给定一棵结点数为n 二叉搜索树，请找出其中的第 k 小的TreeNode结点值。
        1.返回第k小的节点值即可
        2.不能查找的情况，如二叉树为空，则返回-1，或者k大于n等等，也返回-1
        3.保证n个节点的值不一样
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
    int KthNode(TreeNode* proot, int k) {
        // 补充对于根节点为空和k为0时的特殊输入的判断
        if (proot == nullptr) return -1;
        if (k == 0) return -1;

        std::vector<int> vec;
        vec = Inorder(proot, vec);
        if (vec.size() >= k) {
            return vec[k - 1];
        } else
            return -1;
    }

private:
    std::vector<int> Inorder(TreeNode* root, std::vector<int>& inputVec) {  // 一开始没用& 导致传参没被修改  如果不用&的话，调用时就需要inputVec=Inorder()
        // 中序遍历
        if (root->left != nullptr) {
            Inorder(root->left, inputVec);
        }
        inputVec.push_back(root->val);
        if (root->right != nullptr) {
            Inorder(root->right, inputVec);
        }
        return inputVec;
    }
};
int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    

    Solution solutuon;
    std::cout<<"answer is: "<< solutuon.KthNode(root, 3);
    return 0;
}
