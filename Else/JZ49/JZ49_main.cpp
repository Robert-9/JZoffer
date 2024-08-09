/*
    描述
        把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
        习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第 n个丑数。
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1) return 1;
        int i=1, j=1, k=1;  // 分别保存前一个乘2 3 5 的数字

        vector<int> dp;  // 保存第n个丑数
        dp.push_back(0); dp.push_back(1);

        for(int current=2; current<index+1; current++){
            dp.push_back( min( dp[i]*2, min(dp[j]*3, dp[k]*5) ) );

            // 如果 dp[i]*2等于dp[j]*3, i j 在此处都会更新. 其他情况类似
            if(dp[current] == dp[i]*2) i++;
            if(dp[current] == dp[j]*3) j++;
            if(dp[current] == dp[k]*5) k++;
        }
        return dp.back();
    }
};

int main(){
    Solution solution;
    cout << solution.GetUglyNumber_Solution(7);
}