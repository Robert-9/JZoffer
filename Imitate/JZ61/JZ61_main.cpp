/*
    描述
        现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
        有如下规则：
        1. A为1，J为11，Q为12，K为13，A不能视为14
        2. 大、小王为 0，0可以看作任意牌
        3. 如果给出的五张牌能组成顺子（即这五张牌是连续的）就输出true，否则就输出false。
        4.数据保证每组5个数字，每组最多含有4个零，数组的数取值为 [0, 13]
*/

#include <vector>
using namespace std;

class Solution {
private:
    void Merge(vector<int>& nums, int left, int mid, int right){
        /*
            对nums中，left和right之间的部分排序
        */
        vector<int> leftSubVec(nums.begin()+left, nums.begin()+mid+1);
        vector<int> rightSubVec(nums.begin()+mid+1, nums.begin()+right+1);
        
        int i=0, j=0, k=left;
        while(i<leftSubVec.size() && j<rightSubVec.size()){
            if(leftSubVec[i] < rightSubVec[j]){
                nums[k] = leftSubVec[i++];
            }
            else{
                nums[k] = rightSubVec[j++];
            }
            k++;
        }

        while(i<leftSubVec.size()){
            nums[k++] = leftSubVec[i++];
        }
        while(j<rightSubVec.size()){
            nums[k++] = rightSubVec[j++];
        }
    }
    void mergeSort(vector<int>& nums, int left, int right){
        /*
            将nums分为子数组，然后对这些子数组逐级排序
        */
        if(left>=right){
            return ;
        }
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        Merge(nums, left, mid, right);
    }

public:
    bool IsContinuous(vector<int>& numbers) {
        if(numbers.empty()) return false;

        int num0=0, count=0;
        mergeSort(numbers, 0, numbers.size()-1);
        while (numbers[num0] == 0)
        {
            num0++;
        }
        for(int i=num0; i<numbers.size()-1; i++){
            if(numbers[i+1] == numbers[i]) return false;  // 有相同的则不可能是顺子

            count +=(numbers[i+1]-numbers[i]-1);
        }
        if(count > num0) return false;
        else return true;
    }
};
