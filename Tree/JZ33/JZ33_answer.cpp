#include <vector>
#include <iostream>

class Solution {
public:
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        int len = sequence.size();
        if(len == 0) return false;
        if(len == 1) return true;

        return VerifySquenceOfBSTHelper(sequence, 0, len - 1);
    }

private:
    bool VerifySquenceOfBSTHelper(const std::vector<int>& sequence, int start, int end) {
        if (start >= end) return true; // 子数组为空或只有一个元素时，视为有效的后序遍历

        int rootVal = sequence[end];
        int index = end;

        // 找到第一个小于根节点的元素位置，分界点
        while (index > start && sequence[index - 1] > rootVal) {
            index--;
        }

        // 检查左子树中是否有大于根节点的元素
        for (int i = start; i < index - 1; i++) {
            if (sequence[i] > rootVal) {
                return false;
            }
        }

        // 递归检查左右子树
        return VerifySquenceOfBSTHelper(sequence, start, index - 1) &&
               VerifySquenceOfBSTHelper(sequence, index, end - 1);
    }
};

int main() {
    Solution solution;
    std::vector<int> sequence = {5, 7, 6, 9, 11, 10, 8};
    bool result = solution.VerifySquenceOfBST(sequence);

    std::cout << (result ? "True" : "False") << std::endl;
    return 0;
}
