/*
    描述
        给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段，每段绳子的长度记为 k[1],...,k[m] 。
        请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？
        （ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），
*/

#include <algorithm>

class Solution{
public:
    int cutRope(int n){
        int result;
        if(n%3==0){
            result = pow(3, n/3);
        }
        if(n%3 == 1){
            result = pow(3, (n-4)/3);
            result *= 4;
        }
        if(n%3 == 2){
            result = pow(3, n/3);
            result *= 2;
        }

        return result;
    }
};