/*
    对于滑动窗口背景类问题，我们可以通过单调队列这一数据结构高效的求出最值
    单调队列是一种高效处理求滑动窗口最值的数据结构，其本身是一个双端队列(deque)，其可以通过O(n)的线性时间复杂度求出最值
*/

#include <deque>
#include <vector>
using std::vector;
using std::deque;

class Solution {
public:
    std::vector<int> maxInWindows(const std::vector<int>& nums, unsigned int windowSize) {
        std::vector<int> maxValues;  // 保存每个窗口中的最大值
        std::deque<int> indexDeque;  // 队列中保存的是下标而不是元素本身

        for(int currentIndex = 0; currentIndex < nums.size(); currentIndex++) {  // 枚举窗口右端
            
            // 移除不在窗口范围内的下标，保证 indexDeque 中的下标始终只表示当前窗口内的元素
            while(!indexDeque.empty() && currentIndex - indexDeque.front() + 1 > windowSize) {  
                indexDeque.pop_front();  // 当窗口移出队头所在的位置，移出队头
            }
            
            // 确保 indexDeque 中的下标对应的值是单调递减的，队头总是当前窗口中的最大值，保证队列的单调性
            while(!indexDeque.empty() && nums[indexDeque.back()] <= nums[currentIndex]) {  
                indexDeque.pop_back();  // 队列尾部的元素如果小于新加入的元素，则更换尾部，注意这是一个while即如果前面的都小于新元素，前面的都会被pop掉
            }
            // 新元素入队   
            indexDeque.push_back(currentIndex);

            // 当前遍历的长度大于等于窗口长度才开始存储答案
            if(windowSize && currentIndex >= windowSize - 1) {  // 相当于几次循环之后再开始存数据
                maxValues.push_back(nums[indexDeque.front()]);
            }
        }
        return maxValues;
    }
};