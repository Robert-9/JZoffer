#include<vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;  // 如果没有找到重复的数字
    }
};
