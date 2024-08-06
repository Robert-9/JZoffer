/*
    描述
        输入一个长度为 n 整数数组，实现一个函数来调整该数组中数字的顺序，
        使得所有的奇数位于数组的前面部分，所有的偶数位于数组的后面部分，
        并保证奇数和奇数，偶数和偶数之间的相对位置不变。
    S1是时间复杂度O(n) 空间复杂度O(n)
    S2时间O(n^2) 空间O(1)
*/

#include <vector>
using namespace std;
class Solution1 {
public:
    vector<int> reOrderArray(vector<int>& array) {
        if(array.empty()) return array;

        vector<int> resultVec;
        vector<int> evenVec;

        for(int i=0; i<array.size(); i++){
            if(array[i]%2){
                resultVec.push_back(array[i]);
            }
            else{
                evenVec.push_back(array[i]);
            }
        }
        
        resultVec.insert(resultVec.end(), evenVec.begin(), evenVec.end());
        return resultVec;
    }
};


class Solution2 {
public:
    vector<int> reOrderArray(vector<int>& array) {
        if(array.empty()) return array;

        int sortedEnd=0;

        for(int k=0; k<array.size(); k++){
            if(array[k]%2){
                int temp = array[k];
                // 将当前奇数与已排序的位置之间的数字（偶数）都向后移一格
                for(int j=k-1; j>=sortedEnd; j--){  
                    array[j+1] = array[j];
                }
                array[sortedEnd++] = temp;  // 此处的++ 造成sortedEnd只能表示已排序的索引的后一个索引
            }
        }
        return array;
    }
};