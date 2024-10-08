/*
    描述
        如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
        使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/


#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap; // 存较小一半，最大堆
    priority_queue<int, vector<int>, greater<int>> minHeap; // 存较大一半，最小堆

public:
    void Insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double GetMedian() { 
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};
