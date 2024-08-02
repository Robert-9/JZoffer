/*
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
    并将P对1000000007取模的结果输出。 即输出P mod 1000000007
*/
#include <vector>
using namespace std;

class Solution {
private:
    int Merge(vector<int>& nums, int left, int mid, int right){
        vector<int> leftSubVec(nums.begin()+left, nums.begin()+mid+1);
        vector<int> righttSubVec(nums.begin()+mid+1, nums.begin()+right+1);
        
        int i=0, j=0, k=left;
        int reverseNum = 0;

        while(i<leftSubVec.size() && j<righttSubVec.size()){
            if(leftSubVec[i] < righttSubVec[j]){
                nums[k] = leftSubVec[i];
                i++; 
            }
            else{
                nums[k] = righttSubVec[j];
                j++;
                reverseNum += (mid-i+1);
            }
            k++;
        }
        while(i<leftSubVec.size()){  // 如果左子树还有剩余的
                nums[k] = leftSubVec[i];
                i++; k++;
        }
        while(i<righttSubVec.size()){  // 如果左子树还有剩余的
                nums[k] = righttSubVec[j];
                j++; k++;
        }
        return reverseNum;
    }
    int mergeSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return 0;
        }
        int reverseNum = 0;
        int mid = left + (right-left)/2;

        reverseNum += mergeSort(nums, left, mid);
        reverseNum += mergeSort(nums, mid+1, right);

        return  reverseNum + Merge(nums, left, mid, right);
    }
public:
    int InversePairs(vector<int>& nums) {
        /*
            归并排序实现  每交换一次就+1
        */
       mergeSort(nums, 0, 0);
    }
};