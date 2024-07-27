#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    bool IsPopOrder(std::vector<int>& pushV, std::vector<int>& popV) {
        if (popV.size() == 0 || pushV.size() == 0) return false;
        if (popV.size() != pushV.size()) return false; // 长度不一致，不可能是正确的弹出顺序

        std::stack<int> stack;
        int pushIndex = 0;

        for (int i = 0; i < popV.size(); i++) {
            int popNum = popV[i];

            // 当栈为空或栈顶元素不等于当前需要弹出的元素时，继续压栈
            while (stack.empty() || stack.top() != popNum) {
                if (pushIndex >= pushV.size()) {
                    return false; // 所有元素都已经压栈，但仍无法匹配弹出序列
                }
                stack.push(pushV[pushIndex]);
                pushIndex++;
            }

            // 如果栈顶元素等于当前需要弹出的元素，弹出栈顶元素
            if (stack.top() == popNum) {
                stack.pop();
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<int> pushV = {1, 2, 3, 4, 5};
    std::vector<int> popV = {4, 5, 3, 2, 1};

    bool result = solution.IsPopOrder(pushV, popV);
    std::cout << (result ? "True" : "False") << std::endl; // 输出: True

    return 0;
}
