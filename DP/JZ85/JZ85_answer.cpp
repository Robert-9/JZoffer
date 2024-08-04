/*
  1.Kadane's 算法的基本思路
    维护两个变量：
        currentSum：表示以当前元素为结尾的最大子数组和。
        maxSum：表示遍历到当前为止的全局最大子数组和。
    递推关系：
        对于每一个元素 array[i]，判断是将其加入到之前的子数组中（即 currentSum + array[i]），还是从当前元素重新开始一个新的子数组（即 array[i] 本身）。
        具体计算为：
        currentSum=max(currentSum+array[i],array[i])
        然后更新全局最大子数组和：
        maxSum=max(maxSum,currentSum)
    最终结果：
        遍历完数组后，maxSum 就是最大子数组和。
    关键点：
        时间复杂度：Kadane's 算法只需要遍历数组一次，因此时间复杂度为 O(n)。
        空间复杂度：算法只使用了几个额外的变量，因此空间复杂度为 O(1)，即常数级别的额外空间。
        Kadane's 算法是解决最大子数组和问题的高效且经典的方法。它的核心在于通过局部最优（当前子数组和）来推导出全局最优（最大子数组和）。

  2.动态规划
    定义 dp[i] 为以 array[i] 结尾的子数组中和的最大值，然后在遍历过程中找到所有 dp[i] 中的最大值
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        if (array.empty()) return {};

        int maxSum = array[0];
        int currentSum = array[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < array.size(); i++) {
            if (currentSum >= 0) {
                currentSum += array[i];
            } else {
                currentSum = array[i];
                tempStart = i;
            }

            if (currentSum > maxSum || (currentSum == maxSum && i - tempStart > end - start)) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        return vector<int>(array.begin() + start, array.begin() + end + 1);
    }
};



class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        if (array.empty()) return {};

        int maxSum = array[0];
        int currentSum = array[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < array.size(); i++) {
            if (currentSum >= 0) {
                currentSum += array[i];
            } else {
                currentSum = array[i];
                tempStart = i;
            }

            if (currentSum > maxSum || (currentSum == maxSum && i - tempStart > end - start)) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        return vector<int>(array.begin() + start, array.begin() + end + 1);
    }
};