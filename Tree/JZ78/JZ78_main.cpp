/*
    描述
        给定一个节点数为 n 二叉树，要求从上到下按层打印二叉树的 val 值，同一层结点从左至右输出，每一层输出一行，将输出的结果存放到一个二维数组中返回。

    测试已通过！
    GPT的改进是将while(!q.empty()){} 中的两个循环合成了一个，简化了逻辑
*/

#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
private:
    int nodeCount = 1;

public:
    std::vector<std::vector<int>> Print(TreeNode* pRoot){
        std::vector<std::vector<int>> resultVec;
        if(pRoot == nullptr) return resultVec;

        TreeNode* current;
        std::queue<TreeNode*> q;
        std::vector<TreeNode*> nodeVec;
        std::vector<int> valVec;
        q.push(pRoot);

        // 在层序遍历的基础上增加区分 层 的逻辑
        while (!q.empty())
        {
            while(nodeCount){
                current = q.front();
                q.pop();
                nodeCount--;
                valVec.push_back(current->val);
                nodeVec.push_back(current);
            }

            resultVec.push_back(valVec);

            for(int i=0; i<nodeVec.size(); i++){
                if(nodeVec[i]->left != nullptr){
                    q.push(nodeVec[i]->left);
                    nodeCount++;
                }
                if(nodeVec[i]->right != nullptr){
                    q.push(nodeVec[i]->right);
                    nodeCount++;
                }
            }
            std::vector<TreeNode*>().swap(nodeVec);
            std::vector<int>().swap(valVec);
        }
        return resultVec;
    }
};