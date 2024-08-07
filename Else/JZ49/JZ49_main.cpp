/*
    描述
        把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
        习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第 n个丑数。
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1) return 1;
        int nums=1;
        int i=0, j=0, k=0;
        int prev = 1;
        while(nums <= index){
            int mul_2 = pow(2, i+1) * pow(3, j) * pow(5, k);
            int mul_3 = pow(2, i) * pow(3, j+1) * pow(5, k);
            int mul_5 = pow(2, i) * pow(3, j) * pow(5, k+1);
            if(mul_2 < mul_3){
                if(mul_2 < mul_5){
                    i++;
                }
                else {
                    k++;
                }
            }
            else if(mul_3 < mul_5){
                j++;
            }
            else k++;

            nums++;
        }
        return pow(2, i) * pow(3, j) * pow(5, k);
    }
};

int main(){
    Solution solution;
    cout << solution.GetUglyNumber_Solution(7);
}