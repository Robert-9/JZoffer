/*
    描述：
        输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回 true ,否则返回 false 。
        假设输入的数组的任意两个数字都互不相同。

    测试已通过！
    边界条件需要仔细考虑，错了很多次才作对。
*/
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

// class Solution {
// public:
//     bool VerifySquenceOfBST(std::vector<int> sequence) {
//         int len = sequence.size();
//         int index = len-1;  // 先指到最后

//         if(len == 0) return false;
//         if(len == 1) return true;

//         // 提出根节点
//         int rootVal = sequence.back();

//         // 区分左右子树
//         while (index > 0)
//         {
//             if(sequence[--index] < rootVal){
//                 break;
//             }
//         }
//         // 检查左子树中是否有大于根节点的元素
//         for (int i = index; i>=0; i--) {
//             if (sequence[i] > rootVal) {
//                 return false;
//             }
//         }

//         std::vector<int> leftSubtree(sequence.begin(), sequence.begin()+index+1);
//         std::vector<int> rightSubtree(sequence.begin()+index+2, sequence.end()-1);
        
//         // 递归检查左右子树
//         return VerifySquenceOfBST(leftSubtree) &&
//                VerifySquenceOfBST(rightSubtree);
//     }
// };


class Solution {
public:
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        int len = sequence.size();

        if(len == 0) return false;
        if(len == 1) return true;

        bool result = Helper(sequence);
        return result;

    }
private:
    bool Helper(std::vector<int> sequence){
        int len = sequence.size();
        if(len == 1 || len == 0) return true;
        int index = len-1;


        // 提出根节点
        int rootVal = sequence.back();

        // 区分左右子树
        while (index >= 0)
        {
            if(sequence[index] < rootVal){  // 0~index 左子树 index+1~end-1 右子树  注意index<=0的情况
                break;
            }
            else index--;
        }
        // 检查左子树中是否有大于根节点的元素
        for (int i = index; i>=0; i--) {
            if (sequence[i] > rootVal) {
                return false;
            }
        }

        std::vector<int> leftSubtree(sequence.begin(), sequence.begin()+index+1);
        std::vector<int> rightSubtree(sequence.begin()+index+1, sequence.end()-1);
        
        // 递归检查左右子树
        return Helper(leftSubtree) &&
               Helper(rightSubtree);
    }

};



int main() {
    Solution solution;
    // std::vector<int> sequence = {5, 7, 6, 9, 11, 10, 8};
    std::vector<int> sequence = {10, 2};

    bool result = solution.VerifySquenceOfBST(sequence);

    std::cout << (result ? "True" : "False") << std::endl;
    return 0;
}