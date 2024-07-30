/*
    描述
        有一个长度为 n 的非降序数组，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，
        比如[1,2,3,4,5]，变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。
        请问，给定这样一个旋转数组，求数组中的最小值。
    数据范围：
        1≤n≤10000，
    数组中任意元素的值: 
        0≤val≤10000
    要求：
        空间复杂度：O(1) ，时间复杂度：O(logn)

    测试未通过
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int>& nums) {
        if(nums.size() == 0) return -1;

        int left = 0, right = nums.size()-1;
        while(left<=right){
            if(nums[left] < nums[right]){
                return nums[left];
            } 

            int mid = left + (right-left)/2;
            if(nums[mid] > nums[left]){
                left = mid+1;
            }
            else if(nums[mid] < nums[left]){
                right = mid-1;
            }
            else if(nums[mid] == nums[left]){
                right--;
            }
        }
        return nums[left];
    }
};