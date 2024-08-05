/*
    写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

class Solution {
public:
    int Add(int num1, int num2) {
        while (num2 != 0) {
            // 不考虑进位的加法
            int sum = num1 ^ num2;
            // 计算进位
            int carry = (num1 & num2) << 1;
            // 更新num1和num2，继续处理
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};