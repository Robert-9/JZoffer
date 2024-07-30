/*
    描述
        输入一个长度为 n 字符串，打印出该字符串中字符的所有排列，你可以以任意顺序返回这个字符串数组。
        例如输入字符串ABC,则输出由字符A,B,C所能排列出来的所有字符串 ABC,ACB,BAC,BCA,CBA和CAB。
    要求：空间复杂度 O(n!)，时间复杂度 O(n!)
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    string swap(string prev, string behind, vector<string>& inputVec){
        if(behind == "") return "";

        char mid = behind.front();
        behind = behind.substr(1);

        string result = prev + swap(prev, behind, inputVec);

        inputVec.push_back(result);
    }
public:
    vector<string> Permutation(string str) {
        vector<string> vec;
        if(str == "") return vec;

        swap("", str, vec);
        return vec;
    }
};