/*
    用的层序遍历：
        用层序遍历读取树并保存、用层序遍历的结果重构树
*/


#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    char* Serialize(TreeNode *root) {
        if (root == nullptr) return nullptr;

        std::string resultStr;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current != nullptr) {
                resultStr += std::to_string(current->val) + ",";
                q.push(current->left);
                q.push(current->right);
            } else {
                resultStr += "#,";
            }
        }

        resultStr.pop_back(); // 移除最后的逗号
        resultStr.push_back('\0');

        char* result = new char[resultStr.size() + 1];
        std::copy(resultStr.begin(), resultStr.end(), result);
        result[resultStr.size()] = '\0';
        return result;
    }

    TreeNode* Deserialize(char *str) {
        if (str == nullptr || *str == '\0') return nullptr;

        std::string data(str);  // 将字符数组 转换为字符串，方便后续处理。
        std::stringstream ss(data);  // 将字符串流化，方便逐个读取节点值
        std::string tempStr;  // 声明一个用于临时存储读取的节点值 的字符串。

        std::getline(ss, tempStr, ',');
        TreeNode* root = new TreeNode(std::stoi(tempStr));  // 将提出来的字符串转为int并赋值给根节点
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (std::getline(ss, tempStr, ',')) {
                if (tempStr != "#") {
                    TreeNode* leftNode = new TreeNode(std::stoi(tempStr));
                    current->left = leftNode;
                    q.push(leftNode);
                }
            }

            if (std::getline(ss, tempStr, ',')) {
                if (tempStr != "#") {
                    TreeNode* rightNode = new TreeNode(std::stoi(tempStr));
                    current->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
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
    char* serializedTree = solution.Serialize(root);
    std::cout << "Serialized Tree: " << serializedTree << std::endl;

    TreeNode* deserializedTree = solution.Deserialize(serializedTree);

    // 清理内存
    delete[] serializedTree;
    delete deserializedTree->right->right;
    delete deserializedTree->right->left;
    delete deserializedTree->left->right;
    delete deserializedTree->left->left;
    delete deserializedTree->right;
    delete deserializedTree->left;
    delete deserializedTree;

    return 0;
}
