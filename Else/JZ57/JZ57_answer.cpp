/*
    双指针法的逻辑解释
    双指针初始化：
        left 指向数组的起始位置，right 指向数组的末尾。
    迭代：
        如果 array[left] + array[right] 等于目标 sum，那么直接返回这两个数字。
        如果和小于 sum，那么移动左指针 left 以增加和。
        如果和大于 sum，那么移动右指针 right 以减小和。
        终止条件：当 left 超过 right 时，说明无法找到两个数满足条件，返回空数组。
        这个方法时间复杂度是 O(n)，比使用二分查找的实现更高效。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) return vector<int>();

        int left = 0;
        int right = array.size() - 1;

        while (left < right) {
            int currentSum = array[left] + array[right];
            if (currentSum == sum) {
                return {array[left], array[right]};
            } else if (currentSum < sum) {
                left++;
            } else {
                right--;
            }
        }

        return vector<int>();
    }
};
