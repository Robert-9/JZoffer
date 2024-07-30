/*
    描述
        给定一个长度为 n 的数组 num 和滑动窗口的大小 size ，找出所有滑动窗口里数值的最大值。

    此方法的时间复杂度为n*size  因为有两次for遍历
*/
#include <cstddef>
#include <vector>
using std::vector;


class Solution {
private:
    int getMaxNum(vector<int> window, int size){
        int max=window[0];
        for(int j=0; j<size; j++){
            if(window[j]>max) max = window[j];
        }
        return max;
    }
public:
    vector<int> maxInWindows(vector<int>& num, int size) {
        // 为空的判断
        if(num.size()<size || size == 0){
            return {};
        }

        vector<int> resultVec;
        int winNum = num.size() - size + 1;
        for(int i=0; i<winNum; i++){
            std::vector<int> window(num.begin()+i, num.begin()+i+size);
            resultVec.push_back(getMaxNum(window, size));
            
        }
        return resultVec;
    }
};