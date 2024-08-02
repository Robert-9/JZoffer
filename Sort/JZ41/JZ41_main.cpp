/*
    描述
        如何得到一个数据流中的中位数？
        如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
        如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
        使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

    思路
        用堆排序，最大堆保存小的一半数据，最小堆保存大的一半数据，保持二者长度相等或相差1，
        长度差别大时移动相应的堆顶元素。返回时即可根据两个堆顶得到中位数。

    测试未通过，
        试图自己手写两个堆然后排序，一直不对。GPT改写的版本也不能通过测试。
        答案中用了优先队列来实现。优先队列本身就是以最大/最小堆来排列，可以直接用。
*/

#include <vector>
using namespace std;

class Solution {
private:
    vector<int> numStream;
    vector<int> maxHeap;
    vector<int> minHeap;

    void maxHeapify(vector<int>& numStream, int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < numStream.size() && numStream[left] > numStream[largest]){
            largest = left;
        }
        if(right < numStream.size() && numStream[right] > numStream[largest]){
            largest = right;
        }
        if(largest != index){
            swap(numStream[largest], numStream[index]);
            maxHeapify(numStream, largest);
        }
    }

    void buildMaxHeap(vector<int>& numStream){
        for(int i=numStream.size()/2-1; i>=0; i++){
            maxHeapify(numStream, i);
        }
    }

    void minHeapify(vector<int>& numStream, int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < numStream.size() && numStream[left] < numStream[largest]){
            largest = left;
        }
        if(right < numStream.size() && numStream[right] < numStream[largest]){
            largest = right;
        }
        if(largest != index){
            swap(numStream[largest], numStream[index]);
            minHeapify(numStream, largest);
        }
    }
    
    void buildMinHeap(vector<int>& numStream){
        for(int i=numStream.size()/2-1; i>=0; i++){
            minHeapify(numStream, i);
        }
    }

public:
    void Insert(int num) {
        /*
            
        */
        if(maxHeap.empty() || num <= maxHeap[0]){  // 最大堆添加更小的一半数据
            maxHeap.push_back(num);
            buildMaxHeap(maxHeap);
            if(maxHeap.size()-minHeap.size() >= 2){
                minHeap.push_back(maxHeap[0]);
                maxHeap.erase(maxHeap.begin());
                buildMinHeap(minHeap);
                buildMaxHeap(maxHeap);
            }
        }
        else{
            minHeap.push_back(num);
            buildMinHeap(minHeap);    
            if(minHeap.size()-maxHeap.size() >= 2){
                maxHeap.push_back(minHeap[0]);
                minHeap.erase(minHeap.begin());
                buildMinHeap(minHeap);
                buildMaxHeap(maxHeap);
            }           
        }
       
    }

    double GetMedian() { 
        /*
            根据 numStream 的长度来获取中位数
        */
        int len = numStream.size();

        if(len%2){  // 奇数
            return (maxHeap.size()>minHeap.size()) ? (double)maxHeap[0] : (double)minHeap[0];
        }
        else{
            return (double)(minHeap[0] + maxHeap[0])/2;
       }
    }
};