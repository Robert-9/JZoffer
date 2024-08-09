/*
    描述
        输入一个长度为 n 整数数组，数组里面可能含有相同的元素，实现一个函数来调整该数组中数字的顺序，
        使得所有的奇数位于数组的前面部分，所有的偶数位于数组的后面部分，
        对奇数和奇数，偶数和偶数之间的相对位置不做要求，但是要求时间复杂度O(n)空间复杂度O(1).

    测试已通过！
    Solution2是GPT简化后的版本
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> reOrderArrayTwo(vector<int>& array) {
        if(array.empty()) return array;

        int sortedIndex = 0;
        int seenIndex = 0;
        while(array[sortedIndex]%2 != 0) sortedIndex++;
        // while(array[seenIndex]%2 == 0) seenIndex++; // 移到第一个偶数

        seenIndex = sortedIndex;

        while(seenIndex < array.size() && sortedIndex<array.size()){
            if(array[seenIndex]%2 == 1){  // 如果是奇数
                swap(array[seenIndex], array[sortedIndex++]);\
                while(array[sortedIndex]%2 !=0  && sortedIndex<array.size()){  // sortedIndex移动到偶数
                    sortedIndex++;
                }
            }
            seenIndex++;
        }
        return array;
    }
};

class Solution2 {
public:
    vector<int> reOrderArrayTwo(vector<int>& array) {
        if (array.empty()) return array;

        int sortedIndex = 0;
        int seenIndex = 0;

        while (seenIndex < array.size()) {
            if (array[seenIndex] % 2 == 1) { // 如果是奇数
                if (seenIndex != sortedIndex) {
                    swap(array[seenIndex], array[sortedIndex]);
                }
                sortedIndex++;
            }
            seenIndex++;
        }
        return array;
    }
};




int main(){
    Solution solution;
    vector<int> input = {2,4,6,5,7};
    vector<int> res = solution.reOrderArrayTwo(input);

    // cout << "ans is " << res;
}