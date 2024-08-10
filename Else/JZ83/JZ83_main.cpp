/*
    描述
        给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段(m、n都是整数, n>1并且m>1，m<=n), 
        每段绳子的长度记为 k[1],...,k[m] 。请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。
        由于答案过大，请对 998244353 取模。
    数据范围：
        2≤n≤10^14
    进阶：空间复杂度 O(1) ， 时间复杂度 O(logn)

    测试已通过！
    使用的是快速幂方法计算次方，函数入参 base 和 exp 都应设置为 long long 类型 不然会出错
    和JZ14思路相同，只是幂运算时用了快速幂
*/

#include <vector>

#define MOD 998244353

class Solution {
private:
    long long fastPower(long long base, long long exp){
        // 使用快速幂方法 计算 base^exp
        long long result = 1;
        while(exp > 0){
            if(exp & 1){
                result = result * base %  MOD;
            }
            exp = exp >> 1;
            base = base * base %  MOD;
        }
        return result;
    }
public:
    long long cutRope(long long number) {
        long long result;
        if(number == 2) return 1;
        if(number == 3) return 2;
        if(number == 4) return 4;

        if(number%3 == 0){
            result = fastPower(3, number/3);
            return result;
        }
        if(number%3 == 1){
            result =  fastPower(3, number/3-1);
            result = result * 4 % MOD;
            return result; 
        }
        if(number%3 == 2){
            result = fastPower(3, number/3);
            result = result * 2 % MOD;
            return result;
        }
        return 0;
    }
};

int main(){
    Solution solution;
    solution.cutRope(999999999);
}