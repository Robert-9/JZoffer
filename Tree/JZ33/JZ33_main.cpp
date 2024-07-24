/*
    描述：
        输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回 true ,否则返回 false 。
        假设输入的数组的任意两个数字都互不相同。
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

class Solution {
public:
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        int len = sequence.size();
        int index = len-1;  // 先指到最后

        if(len == 0) return false;
        if(len == 1) return true;

        // 提出根节点
        int rootVal = sequence.back();

        // 区分左右子树
        while (index > 0)
        {
            if(sequence[--index] < rootVal){
                break;
            }
        }
        // 检查左子树中是否有大于根节点的元素
        for (int i = index; i>=0; i--) {
            if (sequence[i] > rootVal) {
                return false;
            }
        }

        std::vector<int> leftSubtree(sequence.begin(), sequence.begin()+index-1);
        std::vector<int> rightSubtree(sequence.begin()+index, sequence.end()-1);
        
        // 递归检查左右子树
        return VerifySquenceOfBST(leftSubtree) &&
               VerifySquenceOfBST(rightSubtree);
    }
};