#include <vector>
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
public:
    std::vector<int> PrintFromTopToBottom(TreeNode* root) {
        std::vector<int> result;
        if(root == nullptr) return result;     

        std::queue<TreeNode*> q;
        q.push(root);

       while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);

            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
       }

       return result;
    }
};