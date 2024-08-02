/*
    描述
        给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。
        例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
    思路：
        构建一个包含4个元素的最大堆，当新元素小于堆顶元素时，将新元素换到堆顶，再次堆化。

*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
void maxHeapify(vector<int>& heap, int index){
        /*
            将指定的index视为根节点，对heap中index以后的部分的树进行最大堆化
        */
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < heap.size() && heap[largest] < heap[left]){
           largest = left;
        }
        if(right < heap.size() && heap[largest] < heap[right]){
           largest = right;
        }

        if(largest != index){
            swap(heap[index], heap[largest]);  // largest是左或右节点的索引，交换两个元素的位置
            minHeapify(heap, largest);  // 再以左或右节点为堆顶，维持其子树的最小堆性质
        }
    }
    void minHeapify(vector<int>& heap, int index){
        /*
            将指定的index视为根节点，对heap中index以后的部分的树进行最小堆化
        */
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < heap.size() && heap[smallest] > heap[left]){
           smallest = left;
        }
        if(right < heap.size() && heap[smallest] > heap[right]){
           smallest = right;
        }

        if(smallest != index){
            swap(heap[index], heap[smallest]);  // largest是左或右节点的索引，交换两个元素的位置
            minHeapify(heap, smallest);  // 再以左或右节点为堆顶，维持其子树的最小堆性质
        }
    }
    vector<int>  buildMaxHeap_knums(vector<int>& heap, int k){
        for(int i=(heap.size()-1)/2; i>=0; i--){
            maxHeapify(heap, i);  // 从最大堆的底部往上进行堆化
        }
        vector<int> result(heap.begin(), heap.begin()+k);
        return result;
    }
    vector<int> buildMinHeap_knums(vector<int>& heap, int k){  //构建一个k个元素的堆
        for(int i=k/2-1; i>=0; i--){
            minHeapify(heap, i);  // 从最小堆的底部往上进行堆化
        }
        vector<int> result(heap.begin(), heap.begin()+k);
        return result;
    }
public:
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        vector<int> resultVec;
        if(input.size() == 0 || k==0){
            return resultVec;
        }
        if(input.size() <= k){
            return input;
        }
        resultVec = buildMaxHeap_knums(input, k);
        for(int i=k; i<input.size(); i++){
            if(resultVec[0] > input[i]){
                resultVec[0] = input[i];
                maxHeapify(resultVec, 0);
            }
        }
        return resultVec;
    }
};

int main(){
    Solution solution;
    vector<int> input = {4,5,1,6,2,7,3,8};
    vector<int> output = solution.GetLeastNumbers_Solution(input, 4);
    // cout << "ans is: " << output<< " ";
}