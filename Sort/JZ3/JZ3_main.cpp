/*
    描述
        在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
        也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
    测试已通过
    answer中使用了不需要额外空间的  原地置换  的方法
*/

#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    int duplicate(vector<int>& numbers) {
        set<int> s;
        for(int i=0; i<numbers.size(); i++){
            if(s.count(numbers[i])){
                return numbers[i];
            }
            else s.insert(numbers[i]);
        }
    }
};