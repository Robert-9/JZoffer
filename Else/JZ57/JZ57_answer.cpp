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
