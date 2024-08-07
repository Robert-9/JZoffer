/*
    描述
        输入一个升序数组 array 和一个数字S，在数组中查找两个数，使得他们的和正好是S，
        如果有多对数字的和等于S，返回任意一组即可，如果无法找出这样的数字，返回一个空数组即可。
    测试已通过！

    用的二分查找，根据当前遍历到的数字查找应当对应的另一个数字
    answer中用的双指针法
*/


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    int FindNum(vector<int>& array,int num, int left, int right){
        /*
            查找升序数组left 到 right 范围中是否存在num
        */
        if(left>=right) return -1;

        int mid = left + (right-left)/2;
        if(array[mid] > num){
            right = mid-1;
        } else if(array[mid] < num){
            left = mid+1;
        } else{
            return mid;
        }

        return FindNum(array, num, left, right);
    }
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.empty()) return array;
        vector<int> result;

        for(int i=0; i<array.size(); i++){
            if(array[i] < sum){
                int index = FindNum(array, sum-array[i], 0, array.size()-1);
                if(index!=-1){
                    
                    result.push_back(array[i]);
                    result.push_back(array[index]);
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> result;
    result = solution.FindNumbersWithSum({1,2,4,7,11,15},15);
    // cout << result;
}