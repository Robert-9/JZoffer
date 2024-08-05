/*
    输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。

    测试未通过。
    右移操作在处理负数时可能导致无限循环
    右移操作的工作机制
        右移操作 (>>) 在处理负数时会保留符号位，称为 算术右移。这意味着：
        对于正数，右移时高位补 0。
        对于负数，右移时高位补 1，以保持符号。
        
    正确的按位与的方式见answer
*/

class Solution {
public:
    int NumberOf1(int n) {
        int m = 1, temp = 1, result = 0;
        while(n != 0){
            if(m & n){
                result++;
            }
            n = n << 1;
        }
        return result;
    }
};

int main(){
    Solution solution;
    return solution.NumberOf1(10);

}