/*
    对于一个给定的字符序列  S ，请你把其循环左移 K 位后的序列输出。
    例如，字符序列 S = ”abcXYZdef” , 要求输出循环左移 3 位后的结果，即 “XYZdefabc”

    测试已通过！ 注意n>str.size()时，需要用n去str的长度直至小于
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty()) return str;
        if(n==0) return str;

        while(n>=str.size()){  // 可以简化为if(){n = n % str.size();} 效果相同。
            n-=str.size();
        }

        string strMove(str.begin(), str.begin()+n);     
        for(int i=0; i<str.size()-n; i++){
            str[i] = str[n+i];
        }

        for(int i=0; i<n; i++){
            str[str.size()-n + i] = strMove[i];
        }

        return str;
    }
};


int main(){
    Solution solution;
    solution.LeftRotateString("abc", 10);
}