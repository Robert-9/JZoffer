/*
    描述
        输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
        例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。

    测试已通过
    GPT的意见
        1.isBehind 函数的调用可以优化：
            在每次 if (stack.empty() || stack.top() != popNum) 的检查后调用 isBehind 函数可能会导致不必要的遍历。
            可以直接在主循环中进行压栈操作，而无需每次都调用 isBehind。
        2.边界检查：
            while (pushV[pushIndex] != popNum) 循环后没有检查 pushIndex 是否越界。
        3.逻辑简单化：
            isBehind 函数实际上可以简化为在主循环中直接检查是否需要压栈，并且在压栈过程中直接找到需要的元素。
        详见answer
*/

#include <stack>
#include <vector>
class Solution {
  private:
    bool isBehind(int pushIndex, int popNum, std::vector<int>& pushV) {
        bool result = false;
        for (int j = pushIndex; j < pushV.size(); j++) {
            if (pushV[j] == popNum) result = true; // 在index位置的后面
        }
        return result;
    }
  public:
    bool IsPopOrder(std::vector<int>& pushV, std::vector<int>& popV) {
        if (popV.size() == 0 || pushV.size() == 0) return false;

        std::stack<int> stack;
        int pushIndex = 0;
        int temp = 0;

        for (int i = 0; i < popV.size(); i++) {
            int popNum = popV[i];
            if (stack.empty() || stack.top() != popNum) {
                if (isBehind(pushIndex, popNum, pushV)) {
                    while (pushV[pushIndex] != popNum) { // 将相应的值压入堆栈
                        stack.push(pushV[pushIndex]);
                        pushIndex++;
                    }
                } else return false;
                pushIndex++;
            }
			else if (stack.top() == popNum) {
                stack.pop();
            }
        }
        return true;
    }
};