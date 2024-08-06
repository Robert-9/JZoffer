#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 检查有符号整数
    bool integer(string& s, int& index, int end) {
        if (index < end && (s[index] == '-' || s[index] == '+'))
            index++;
        return unsigned_integer(s, index, end);
    }

    // 检查无符号整数
    bool unsigned_integer(string& s, int& index, int end) {
        int temp = index;
        while (index < end && (s[index] >= '0' && s[index] <= '9'))
            index++;
        return index > temp;
    }

    // 去除前导和尾随空格
    void trimSpaces(string& str, int& start, int& end) {
        while (start < end && str[start] == ' ')
            start++;
        while (end > start && str[end - 1] == ' ')
            end--;
    }

    bool isNumeric(string str) {
        if (str.empty())
            return false;

        int start = 0, end = str.length();
        trimSpaces(str, start, end);

        if (start >= end)
            return false;

        int index = start;
        bool flag = integer(str, index, end);

        if (index < end && str[index] == '.') {  // 整数+ . +整数
            index++;
            flag = unsigned_integer(str, index, end) || flag;
        }

        if (index < end && (str[index] == 'e' || str[index] == 'E')) {  // 整数or小数+e+整数
            index++;
            flag = flag && integer(str, index, end);
        }

        return flag && (index == end);
    }
};


int main(){
    Solution solution;
    bool res = solution.isNumeric("+-8.8");
    cout << "result is "<< res;

}