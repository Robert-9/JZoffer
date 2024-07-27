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
private:
    TreeNode* isSubtree(TreeNode* root1, TreeNode* root2){
        /*
            @当根节点相同时，判断剩下的节点是否相同
            @return:
                返回非空指针时，说明剩下的节点不完全相同;
                返回空指针则说明是子树
        */
        if(root2 == nullptr) return nullptr; // 树B 的子节点全部走完，说明所有节点全部相同了
        else if(root1 == nullptr) return root2;// 树B未走完，但树A走完了，不对

        if(root1->val == root2->val){
            TreeNode* isLeftSubtree = isSubtree(root1->left, root2->left);
            TreeNode* isRightSubtree = isSubtree(root1->right, root2->right);
            if(isLeftSubtree == nullptr && isRightSubtree == nullptr){
                return nullptr;
            }
            else{
                return root2;
            }
        }
        else{
            return root2;
        }

        return nullptr;
    }
    bool Preoder(TreeNode* root1, TreeNode* root2){
        bool is = false;
        if(root1 == nullptr) return false;

        // if(root1->val == root2->val){
            is = isSubtree(root1, root2) == nullptr;
        // }
        return is || Preoder(root1->left, root2) || Preoder(root1->right, root2);
    }

public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        
        return Preoder(pRoot1, pRoot2);

    }
};


int main() {
    TreeNode* root1 = new TreeNode(8);
    root1->left = new TreeNode(8);
    // root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(9);
    // root1->right->left = new TreeNode(13);
    // root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(2);
    // root1->left->left->right = new TreeNode(2);
    // root1->right->right->left = new TreeNode(5);
    // root1->right->right->right = new TreeNode(1);
    root1->left->left->left->left = new TreeNode(5);


    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(9);
    // root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(2);


    Solution solution;
    bool result = solution.HasSubtree(root1, root2);

    std::cout << "The answer is: " << result << std::endl;

    return 0;
}