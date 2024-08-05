/*
    n&(n-1)的作用是将 n 的二进制表示中最右边的 1 变成 0。因此，每次操作都会减少一个 1，直到 n 变为 0。
*/

class Solution {
public:
    int NumberOf1(int n) {
        int result = 0;
        while (n != 0) {
            result++;
            n = n & (n - 1);  // 清除最低位的1
        }
        return result;
    }
};
