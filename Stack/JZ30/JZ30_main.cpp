/*
    描述
        定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
*/
#include <vector>

class Solution {
public:
    void push(int value) {
        stack.push_back(value);
    }
    void pop() {
        if(!stack.empty()){
            stack.erase(stack.end());
        }
    }
    int top() {
        if(!stack.empty()){
            return stack.back();
        }
    }
    int min() {
        if(!stack.empty()){
            int result = stack.front();
            for(int i=1; i<stack.size(); i++){
                if(result > stack[i]){
                    result = stack[i];
                }
            }
            return result;
        }
        return 0;
    }
private:
    std::vector<int> stack;

};