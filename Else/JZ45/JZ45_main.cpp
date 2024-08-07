/*
    描述
        输入一个非负整数数组,把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

    测试已通过
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    bool compare(int num1, int num2){
        /*
            将两个数分别放在另一个数前面，若num1在前面时更大，则返回true
        */
        int i=10;
        while(num2/i>0){
            i *= 10;
        }
        int num_1_2 = num1 * i + num2;
        i = 10;
        while(num1/i>0){
            i *= 10;
        }
        int num_2_1 = num2 * i + num1;
        if(num_1_2 > num_2_1){
            return true;
        }
        else return false;

    }
public:
    string PrintMinNumber(vector<int>& numbers) {
        string resultStr;
        if(numbers.empty()) return  resultStr;

        int j=0;
        for(int i=0; i<numbers.size()-1; i++){
            for(j=0; j<numbers.size()-i-1; j++){
                if(compare(numbers[j], numbers[j+1])){
                    swap(numbers[j], numbers[j+1]);
                }
            }
        }

        for(int k=0; k<numbers.size(); k++){
            resultStr += (to_string(numbers[k]));
        }

        return resultStr;
    }
};

int main(){
    Solution solution;
    vector<int> inputVec = {1, 3, 22};

    cout << solution.PrintMinNumber(inputVec);
}