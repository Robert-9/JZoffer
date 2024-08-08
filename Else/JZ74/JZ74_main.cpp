/*
    找出所有和为sum的连续正数序列
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum == 0 || sum ==1) return result;

        int left=1, right=1;
        int bound = (sum+1)/2;
        while(right<=bound){
            if((left+right)*(right-left+1)/2 > sum){  //求和公式
                left++;
            } else if((left+right)*(right-left+1)/2 < sum){
                right++;
            } else{ // 等于
                vector<int> res;
                for(int i=left; i<=right; i++){
                    res.push_back(i);
                }
                result.push_back(res);
                left++;
            }
        }
        return result;
    }
};