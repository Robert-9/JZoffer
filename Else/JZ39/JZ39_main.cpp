/*
    描述
        给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        unordered_map<int, int> hash;

        for(int i=0; i<numbers.size(); i++){
            hash[numbers[i]]++;
        }
        // int max;
        for(auto pair: hash){
            if(pair.second*2>numbers.size())
            return pair.first;
        }
    }
};