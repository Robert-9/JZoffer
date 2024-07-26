/*
    描述
        请实现两个函数，分别用来序列化和反序列化二叉树，不对序列化之后的字符串进行约束，但要求能够根据序列化之后的字符串重新构造出一棵与原二叉树相同的树。
        二叉树的序列化(Serialize)是指：
            把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
            序列化可以基于先序、中序、后序、层序的二叉树等遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#）
        二叉树的反序列化(Deserialize)是指：
            根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。


*/

#include <string>
#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool leftNodeAssigned = 0;
    bool rightNodeAssigned = 0;

public:
    char* Serialize(TreeNode *root) {
        if(root == nullptr) return nullptr;

        std::string resultStr;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            // 把当前节点的值加到字符串的末尾
            if(current != nullptr){
                resultStr += (std::to_string(current->val)) + ",";
                q.push(current->left);
                q.push(current->right);
            }
            else{
                resultStr += "#,";
            }
            
        }
        resultStr.push_back('\0');
        return &resultStr[0];
    }

    TreeNode* Deserialize(char *str) {
        TreeNode* pHead;
        TreeNode* pCur = pHead;
        TreeNode* tempNode;
        if(str == nullptr) return pHead;

        std::queue<TreeNode*> q;
        while (str!='\0')
        {
            char tempC = *str;

            // 将字符串中的值取出来
            if(tempC == '#'){
                tempNode = nullptr;
            }
            else if(tempC == ','){
                ;
            }
            else{
                int val = int(tempC);
                tempNode = new TreeNode(val);
                q.push(tempNode);
            }

            // 关联节点，重建二叉树
            if(!leftNodeAssigned){
                pCur->left = tempNode;
                leftNodeAssigned = 1;
            }
            else{
                pCur->right = tempNode;
                rightNodeAssigned = 1;
            }

            if(leftNodeAssigned && rightNodeAssigned){  // 当前的子节点赋值完成
                q.pop();
                leftNodeAssigned = rightNodeAssigned = 0;
                pCur = q.front();
            }

            str++;
        }
        return pHead;
        
    }
};


int main() {
    // 创建一个示例二叉树:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    char* c = solution.Serialize(root);
    std::cout << c << std::endl;

    solution.Deserialize(c);
    // 清理内存
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
