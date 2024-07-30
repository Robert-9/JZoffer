/*
    描述
        给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数

*/
#include <vector>
using namespace std;

class Solution {
private:
    int findIndexNums(vector<int>& nums, int index) {
        /*
            找到和对应下标的值相同的元素个数
        */
       // 向左寻找
       int leftIndex = index;
       int rightIndex = index;
       while(nums[leftIndex] == nums[index]){  // 向左寻找 
            if(leftIndex>=0){
                leftIndex--;
            }
       }
       while (nums[rightIndex] == nums[index]){  // 向右寻找
            if(leftIndex<=nums.size()-1){
                rightIndex++;
            }
       }
       return rightIndex-leftIndex-1;

    }
public:
    int GetNumberOfK(vector<int>& nums, int k) {
        // 数组为空 或 k不在nums中  均返回0
        if(nums.empty()) return 0;

        int left = 0;
        int right = nums.size()-1;
        int midIndex;

        while(left < right){

            midIndex = left + (right-left)/2;

            if(nums[midIndex] == k){
                int result = findIndexNums(nums, midIndex);  // 计算同一值出现的次数
                return result;
            }
            else if(nums[midIndex] > k){
                left = midIndex;
            }
            else if(nums[midIndex] < k){
                right = midIndex;
            }
        }
        return 0;
    }
};

int main(){
    Solution solution;
}