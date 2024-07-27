/*
    描述
        用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 
        队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。

    测试已通过！
*/

#include <stack>
#include <iostream>

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(stack2.empty() && !stack1.empty()){  // 堆栈1非空，堆栈2空  先将堆栈1中的东西全部压入堆栈2，再弹出其顶端的元素
            stack2.push(stack1.top());
            stack1.pop();
        }
        if (!stack2.empty())
        {
            int result = stack2.top();
            stack2.pop();
            return result;
        }

        return 0;
        
        
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};


int main(){
    Solution solution;
    solution.push(2);
    solution.push(1);
    solution.push(4);

    std::cout<< "pop:" << solution.pop() << solution.pop() << solution.pop();
}