/*
    描述
        我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。
        请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，从同一个方向看总共有多少种不同的方法？
*/

#include<vector>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if(number == 0) return 0;
        if(number == 1) return 0;

        int result = 0;
        int prev1 = 0;
        int prev2 = 1;

        for(int i=0; i<number; i++){
            result += prev1 + prev2;
            prev1 = result;
            prev2 = prev1;
        }

    }
};