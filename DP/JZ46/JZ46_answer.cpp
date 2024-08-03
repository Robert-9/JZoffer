#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(string nums) {
        if (nums.empty() || nums[0] == '0') return 0;

        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // 空字符串有一种解码方式
        dp[1] = 1; // 一个有效的数字（非0）有一种解码方式

        for (int i = 2; i <= n; i++) {
            int oneDigit = nums[i - 1] - '0';
            int twoDigits = (nums[i - 2] - '0') * 10 + oneDigit;

            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
