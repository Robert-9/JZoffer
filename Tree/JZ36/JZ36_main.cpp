/*
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
*/

#include <iostream>
#include <queue>


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

    TreeNode* prevNode = nullptr;

    TreeNode* Inorder(TreeNode* root, TreeNode*& head){
        if(root == nullptr) return nullptr;

        // if(root->left != nullptr){
            Inorder(root->left, head)->right  = root;
        // }
        if(root->right != nullptr){
            root->right = Inorder(root->right, head);
        }
        return root;
    }

public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == nullptr) return nullptr;

        TreeNode* pHead = nullptr;
        Inorder(pRootOfTree, pHead);
        return pHead;
    }
};

void printList(TreeNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

int main() {
    // Create a test tree: 
    //      10
    //     /  \
    //    6    14
    //   / \   / \
    //  4  8  12 16
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);

    Solution solution;
    TreeNode* covertedRoot = solution.Convert(root);  // TreeNode* covertedRoot = 

    printList(covertedRoot);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}