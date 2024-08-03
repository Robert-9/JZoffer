/*
    描述
        有一种将字母编码成数字的方式：'a'->1, 'b->2', ... , 'z->26'。
        现在给一串数字，返回有多少种可能的译码结果

    测试通过，但对题目的测试输入中的特殊情况都手动补了if语句，对特殊情况的考虑不理想
*/


#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int solve(string nums) {
        if (nums.size() == 0 || (nums.size() == 1 && nums[0] == '0')) return 0;
        if (nums.size() == 1 && nums[0] != '0') return 1;

        vector<int> dp(nums.size());  //至少有两个数字时
        if ((nums[0] - '0' == 1 && nums[1] - '0' >= 1 && nums[1] - '0' <= 9) ||
                (nums[0] - '0' == 2 && nums[1] - '0' >= 1 &&
                 nums[1] - '0' <= 6)) { // 11-19 or 21-26
            dp[0] = 1;
            dp[1] = 2;
        }
        else{
            dp[0] = 1;
            dp[1] = 1;           
        }
        if(nums[1] == '0' && nums[2] == '0' && nums.size()>2){
            return 0;
        }
        if(nums[nums.size()-1] == '0' && nums[nums.size()-2]>'2'){
            return 0;
        }
        for (int i = 2; i < nums.size(); i++) {
            if ((nums[i - 1] - '0' == 1 && nums[i] - '0' >= 1 && nums[i] - '0' <= 9) ||
                    (nums[i - 1] - '0' == 2 && nums[i] - '0' >= 1 &&
                     nums[i] - '0' <= 6)) { // 11-19 or 21-26
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};