#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digit = 1;
        long long start = 1;
        long long count = 9;

        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = digit * start * 9;
        }

        start += (n - 1) / digit; // 找到具体的数字
        string number = to_string(start);
        return number[(n - 1) % digit] - '0'; // 转换为int类型
    }
};

int main(){
    Solution solution;
    int ans = solution.findNthDigit(1000000000);
    std::cout << "answer is " << ans;
}