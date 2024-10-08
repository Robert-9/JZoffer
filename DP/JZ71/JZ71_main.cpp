/*
    一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
    求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。
 */

#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=number; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j];
            }
        }
        return dp[number];
    }
};