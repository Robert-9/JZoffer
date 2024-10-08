/*
    请实现一个函数用来判断字符串str是否表示数值（包括科学计数法的数字，小数和整数）。

    测试已通过
    相较于answer，逻辑复杂一些。区别在于一开始理解错了题目的意思，
        输入只会有一段有内容的字符串，即"空格 内容 空格"  不会用空格区分多组内容
        所以answer中用的是按index顺序读，不需要循环。有整数再看有没有小数点，再看有没有e，
        只有判断整数需要单独的函数其他的情况可以顺序只执行一次。
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool isScientific(vector<char> strVec){
        auto it1 = find(strVec.begin(), strVec.end(), 'e');
        auto it2 = find(strVec.begin(), strVec.end(), 'E');
        int index_e = 0;

        if(it1 == strVec.end() && it2 == strVec.end()) 
            return false;
        else if(it1 != strVec.end()){
            index_e = distance(strVec.begin(), it1);
        }
        else{
            index_e = distance(strVec.begin(), it2);
        }

        // 看e前后的类型
        if((isInteger(strVec, 0, index_e-1) || isDecimal(strVec, 0, index_e-1))
            && isInteger(strVec, index_e+1, strVec.size()-1))
            return true;
        else
            return false;
    }   
    bool isDecimal(vector<char> strVec, int start, int end){
        if(strVec[start] =='+' || strVec[start] == '-'){ 
            start += 1;
            // strVec.erase(strVec.begin());
        }
        if(start>end) return false;

        auto it = find(strVec.begin(), strVec.begin()+end+1, '.');
        int index_dot = distance(strVec.begin(), it);

        if(index_dot == start){
            return isInteger(strVec, start+1, end);
        }
        else if(index_dot == end){
            return isInteger(strVec, start, end-1);
        }
        else{
            return isInteger(strVec, start, index_dot-1) && isInteger(strVec, index_dot+1, end);
        }
    } 
    bool isInteger(vector<char> strVec, int start, int end){
        if(strVec[start] =='+' || strVec[start] == '-'){
            start += 1;
            // strVec.erase(strVec.begin());
        }
        if(start>end) return false;

        for(int i=start; i<end+1; i++){
            if(strVec[i] > '9' || strVec[i] < '0'){
                return false;
            }
        }
        return true;
    }
public:
    bool isNumeric(string str) {
        if(str.empty()) return false;

        for(int index=0; index<str.size(); index++){
            vector<char> strVec;
            int start = 0;

            if(str[index] == ' ') continue;

            // if( !(str[index] == '+' || str[index] == '-'  || str[index] == '.' || str[index] == 'e'
            //         || (str[index] <= '9' && str[index] >= '0')) ){
            //             continue;
            //         }
            else{
                start = index;
                while(index <str.size() && str[index] != ' '){
                    strVec.push_back(str[index]);
                    index++;
                }
                if(index>start) index--;
            }
            if(isScientific(strVec) || isDecimal(strVec, 0, strVec.size()-1) || isInteger(strVec, 0, strVec.size()-1)) return true;
            strVec.clear();
        }

        return false;
    }
};

int main(){
    Solution solution;
    bool res = solution.isNumeric("a11");
    cout << "result is "<< res;

}