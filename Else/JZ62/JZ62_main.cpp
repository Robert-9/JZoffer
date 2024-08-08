/*
    描述
        让 n 个小朋友们围成一个大圈，小朋友们的编号是0~n-1。随机指定一个数 m ，让编号为0的小朋友开始报数。每次喊到 m-1 的那个小朋友要出列不再回到圈中，
        从他的下一个小朋友开始，继续0... m-1报数....直到剩下最后一个。求其编号。
    测试已通过，
        思路分三步： 1.计算 要移动的步数；
                    2.判断 是向前还是向后(>0向前 <0向后)，<0 则要将步数 +n 取补；
                    3.移动 当前位置+步数 没走到末端则直接走，走到末端了则用 -n 取补
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        vector<int> remainVec;
        for(int i=0; i<n; i++){
            remainVec.push_back(i);
        }

        int curIndex = 0;
        int steps = 0;  // 要往后走的步数  比m少1(因为不包括当前位置的)

        while(remainVec.size()>1){
            n = remainVec.size();
            if(m>n) steps = m%n -1;  // 避免当m>n时溢出  m和n都是从0开始 到m-1/n-1结束
            else steps = m-1;

            while(curIndex + steps < 0){
                steps+=n;
            }

            if(curIndex + steps < n){
                remainVec.erase(remainVec.begin()+curIndex+steps);
                curIndex += steps;
                if(curIndex == n-1){
                    curIndex = 0;
                }
            }
            else if(curIndex + steps >= n){
                remainVec.erase(remainVec.begin()+curIndex+steps-n);
                curIndex = curIndex+steps-n;
            }
            
        }
        return remainVec[0];
    }
};

int main(){
    Solution solution;
    int res = solution.LastRemaining_Solution(6, 6);

    cout << "ans is " << res;
}