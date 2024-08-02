/*
    描述
        如何得到一个数据流中的中位数？
        如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
        如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
        使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
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

    void buildMaxHeap(vector<int>& numStream, int index){
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
    
    void buildMinHeap(vector<int>& numStream, int index){
        for(int i=numStream.size()/2-1; i>=0; i++){
            maxHeapify(numStream, i);
        }
    }

public:
    void Insert(int num) {
        /*
            将数据添加到 numStream 中，并完成排序
        */
        if(maxHeap.size()-minHeap.size()<1){  // 比较大小堆的长度
            maxHeap.push_back(num);
            buildMaxHeap(maxHeap, 0);
        }
        else{
            minHeap.push_back(num);
            buildMinHeap(minHeap, 0);
        }
       
    }

    double GetMedian() { 
        /*
            根据 numStream 的长度来获取中位数
        */
        int len = numStream.size();

        if(len%2){  // 奇数
            return maxHeap[0];
        }
        else{
            return (minHeap[0] + maxHeap[0])/2;
       }
    }
};