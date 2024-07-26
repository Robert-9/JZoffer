/*
    描述
        给定一棵二叉树(保证非空)以及这棵树上的两个节点对应的val值 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。

    思路：
        ○ 递归检查当前节点是否为 o1 或 o2，如果是则返回当前节点。
		○ 递归检查左子树和右子树，如果 o1 和 o2 分别在左右子树中，那么当前节点就是它们的最近公共祖先。
        ○ 如果 o1 和 o2 都在左子树或右子树中，那么返回该子树的结果。

 */

#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
    TreeNode* Preoder(TreeNode* root, int o1, int o2){
        if(root == nullptr || root->val == o1 || root->val == o2){
            return root;
        }

        TreeNode* leftResult = Preoder(root->left, o1, o2);
        TreeNode* rightResult = Preoder(root->right, o1, o2);
        if(leftResult != nullptr && rightResult != nullptr){
            return root;
        }
        else if(leftResult != nullptr && rightResult == nullptr){
            return leftResult;
        }
        else if(leftResult == nullptr && rightResult != nullptr){
            return rightResult;
        }
    }


public:
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // 本题保证非空

        // std::queue<TreeNode*> q;
        // q.push(root);
        // TreeNode* currNode;
        // int o1_depth = 0;
        // int o2_depth = 0;
        // int cur_depth = 1;
        Preoder(root, o1, o2);
        // 层序遍历找节点
        // while (!q.empty())
        // {
        //     int nodeCount = q.size();  // 当前层的节点数

        //     for(int i=0; i<nodeCount; i++){
        //         currNode = q.front();
        //         q.pop();
        //         // 层序遍历找到相应的节点了，保存层数，保存节点。
        //         if(currNode->val == o1){
        //             TreeNode* o1_in_tree = currNode;
        //             o1_depth = cur_depth;
        //         }
        //         else if(currNode->val == o2){
        //             TreeNode* o2_in_tree = currNode;
        //             o2_depth = cur_depth;
        //         }
        //         // 两个都已经找到
        //         if(o1_depth && o2_depth){
        //             break;
        //         }
        //         // 还没找到两个，将剩下的节点继续压入队列
        //         if(currNode->left != nullptr){
        //             q.push(currNode->left);
        //         }
        //         if(currNode->right != nullptr){
        //             q.push(currNode->right);
        //         }                
        //     }
        //     cur_depth++;
        // }
        // 找到节点后，由根向下找


        // 递归找

        
    }
};