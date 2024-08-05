/*
    实现函数 double Power(double base, int exponent)，求base的exponent次方。
*/

// #include 

class Solution {
public:
    double Power(double base, int exponent) {
        int result = 1;

        while(exponent){
            if(exponent & 1){
                result *= base;
            }
            base *= base;
            exponent >> 1;
        }
       return result;
    }
};