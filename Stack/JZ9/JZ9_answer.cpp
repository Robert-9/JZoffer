#include <stack>
#include <iostream>

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 如果 stack2 仍然为空，说明队列是空的
        if (stack2.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};
