#include<vector>
#include<iostream>
using namespace std;

class Solution {
  public:
    vector<int> FindNumsAppearOnce(vector<int>& nums) {
        vector<int> result(2);
        if (nums.size() == 0) return result;

        int diff = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff = diff ^ nums[i];
        }

        int mask = 1;
        while ((diff & mask) == 0) {
            mask <<= 1;
        }

        for (int j = 0; j < nums.size(); j++) {
            if ((nums[j] & mask) == 0) {
                if (result[0] == 0) {
                    result[0] = nums[j];
                } else {
                    result[0] = result[0] ^ nums[j];
                }
            } else {
                if (result[1] == 0) {
                    result[1] = nums[j];
                } else {
                    result[1] = result[1] ^ nums[j];
                }
            }
        }
        if (result[0] > result[1]) swap(result[0], result[1]);

        return result;
    }
};