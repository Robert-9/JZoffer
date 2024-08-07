#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int n) {
        if (n <= 0) return 0;  // 边界条件
        if (n == 1) return 1;  // 第一个丑数是1
        
        std::vector<int> dp(n);
        dp[0] = 1;  // 第一个丑数是1
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; ++i) {
            int next_ugly = std::min({dp[i2] * 2, dp[i3] * 3, dp[i5] * 5});
            dp[i] = next_ugly;
            
            if (next_ugly == dp[i2] * 2) ++i2;
            if (next_ugly == dp[i3] * 3) ++i3;
            if (next_ugly == dp[i5] * 5) ++i5;
        }
        
        return dp[n - 1];
    }
};


int main(){
    Solution solution;
    cout << solution.GetUglyNumber_Solution(7);
}
