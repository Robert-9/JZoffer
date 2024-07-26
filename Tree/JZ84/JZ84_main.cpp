/*
    描述
        给定一个二叉树root和一个整数值 sum ，求该树有多少路径的的节点值之和等于 sum 。
        1.该题路径定义不需要从根节点开始，也不需要在叶子节点结束，但是一定是从父亲节点往下到孩子节点
        2.总节点数目为n

    测试已通过！
    看了一点讲解中的思路，同时第一遍写得有点问题，参考了GPT给出的修改意见。

    GPT对当前main的建议：
        1.函数命名：calAllPah 改为 calAllPaths 会更符合其功能。
        2.减少全局变量使用：inputSum 和 pathNum 不需要是成员变量，可以在 FindPath 方法中传递参数。
        3.代码简化：可以简化一些逻辑，使代码更清晰。
    具体修改见answer
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int inputSum = 0;
    int pathNum = 0;

    int calAllPah(TreeNode* root, int curSum){
        /*
            计算以输入节点为根节点的树的所有路径中 和为num的个数
            @return: 一条路径的和
        */
       if(root == nullptr) return 0;

        curSum += root->val;
        if(curSum == Solution::inputSum){
            pathNum += 1;
        }

        calAllPah(root->left, curSum);
        calAllPah(root->right, curSum);
        return curSum;
    }

    void Preorder(TreeNode* root){
        if(root == nullptr) return;

        calAllPah(root, 0);
        Preorder(root->left);
        Preorder(root->right);
    }
public:
    int FindPath(TreeNode* root, int sum) {
        if(root == nullptr) return 0;

        inputSum = sum;

        Preorder(root);

        return pathNum;

    }
};