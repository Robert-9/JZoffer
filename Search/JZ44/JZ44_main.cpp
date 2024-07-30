/*
    描述
        数字以 0123456789101112131415... 的格式作为一个字符序列，在这个序列中第2位（从下标 0 开始计算）是2，第10位是1，第13位是1，以此类题，
        请你输出第 n 位对应的数字。

    测试已通过 做了一天 最后静下来慢慢调试找错误过的
*/
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    int findNthDigit(int n) {
        if(n==0) return 0;

        int res = n;
        int digit = 1;
        long bound = 0;
        while(1){
            bound = 9*pow(10, digit-1)*(digit);
            if(res > bound){
                res = res - bound; // res是去掉前面固定的以后的剩下的数字量
                digit++;
            }
            else break;
            
        }
        int nums = res/(digit) ;  // 除以当前的位数  得到数字的个数
        int prev = (digit>1) ? pow(10, digit-1) + nums : nums;  // bound+数字个数

        res = res % digit;
        int cur = (res>0) ? prev + 1 : prev;  // 得到当前的数字
          
        string result = to_string(cur);
        if(res>0) return result[res-1]-'0';
        else return result.back()-'0';
    }
};


int main(){
    Solution solution;
    int ans = solution.findNthDigit(1000000000);
    std::cout << "answer is " << ans;
}

