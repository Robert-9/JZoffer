#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int>& nums) {
        if(nums.size() == 0) return -1;

        int left = 0, right = nums.size()-1;
        while(left < right){
            if(nums[left] < nums[right]){
                return nums[left];
            } 

            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]){
                left = mid+1;
            }
            else if(nums[mid] < nums[right]){
                right = mid;
            }
            else if(nums[mid] == nums[right]){
                right--;
            }
        }
        return nums[left];
    }
};