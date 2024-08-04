/*
    描述
        输入一个长度为n的整型数组array，数组中的一个或连续多个整数组成一个子数组，找到一个具有最大和的连续子数组。
        1.子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3]，[3,5,7]等等，但是[1,3,7]不是子数组
        2.如果存在多个最大和的连续子数组，那么返回其中长度最长的，该题数据保证这个最长的只存在一个
        3.该题定义的子数组的最小长度为1，不存在为空的子数组，即不存在[]是某个数组的子数组
        4.返回的数组不计入空间复杂度计算

    对于dp数组表示的意义没有考虑清楚，不合适的dp会导致状态转移方程复杂。
*/

// 如果下一个数是正数 就一定要加  如果是负数则要考虑是否加
#include<vector>
#include<iostream>
using namespace std;

class Solution {
  public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        /*
            空间复杂度O(n)
        */
        if (array.empty()) return array;

        int maxVal = 0;
        int left = 0, right = 0;

        vector<int> dp(array.size() + 1);
        while (array[left] < 0) {
            left++;
        }
        dp[left] = array[left];
        right = left;
        for (int i = left+1; i < array.size(); i++) { // i表示当前遍历到的位置
            if (array[i] >= 0) {
                if (right == i - 1) {
                    dp[i] = dp[i - 1] + array[i];
                    right++;
                } else { // 前面有负数 比较从前一个最大值加到现在，以及不加的大小
                    int temp = dp[i - 1];
                    for (int j = right+1; j <= i; j++) {
                        temp += array[j];
                    }
                    if (dp[i-1] <= temp) { // 从left加到i 大于 i位置的值
                        dp[i] = temp;
                        right = i;
                    } else {
                        dp[i] = dp[i-1];
                    }
                    
                }
            } else { // 负数 right 不一定要加
                dp[i] = dp[i - 1];
            }
        }
        return vector<int>(array.begin() + left, array.begin() + right + 1);
    }
};




int main(){
    Solution solution;
    vector<int> array = {1,2,-3,4,-1,1,-3,2};

    vector<int> result = solution.FindGreatestSumOfSubArray(array);
    for(int k=0; k<result.size(); k++){
        cout << result[k] << " ";
    }
}