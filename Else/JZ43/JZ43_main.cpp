/*
    描述
        输入一个整数 n ，求 1～n 这 n 个整数的十进制表示中 1 出现的次数
        例如， 1~13 中包含 1 的数字有 1 、 10 、 11 、 12 、 13 因此共出现 6 次

    测试未通过  正确答案见answer
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if(n<10) return 1;

        int result =0;
        int bitNum=10;
        while(n/bitNum>0){
            if(n/bitNum >= 10){
                result += n/bitNum/10 * bitNum;
            }
            else if(n/bitNum > 1){
                result += 1 * bitNum;
            }
            else
                result += (1 * n%bitNum +1);
            bitNum *= 10;
        }
        // 个位的1
        if(n%10 == 0){
            result = result + (n/10);
        }
        else
            result = result + (n/10) + 1;
        return result;
    }
};

int main(){
    Solution solution;
    cout << solution.NumberOf1Between1AndN_Solution(10000); 
}