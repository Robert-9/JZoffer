/*
    地上有一个 rows 行和 cols 列的方格。坐标从 [0,0] 到 [rows-1,cols-1] 。
    一个机器人从坐标 [0,0] 的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于 threshold 的格子。 
    例如，当 threshold 为 18 时，机器人能够进入方格   [35,37] ，因为 3+5+3+7 = 18。但是，它不能进入方格 [35,38] ，因为 3+5+3+8 = 19 。
    请问该机器人能够达到多少个格子？
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_set<vector<int>> seen;

    int search(int x, int y, int threshold, vector<vector <int>>& matrix){
        /*
            从当前节点出发，可以到的格子
        */
        // 注意可以走走过的点
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y] || !underThreshold(x, y, threshold)){
            return 0;
        }
        matrix[x][y] = 1;

        return 1 +  search(x+1, y, threshold, matrix) + 
                    search(x-1, y, threshold, matrix) + 
                    search(x, y+1, threshold, matrix) + 
                    search(x, y-1, threshold, matrix);

    }
    bool underThreshold(int x, int y, int threshold){
        /*
            用于判断 x y 提取出来是否都小于阈值
        */
        int val=0;
        while(x >0){
            val += x % 10;
            x = x/10;
       }
        while(y >0){
            val += y % 10;
            y = y/10;
       }
       if(val >= threshold) return false;
       else return true;
    }

public:
    int movingCount(int threshold, int rows, int cols) {
        // 似乎没有为空的情况
        // if(){
        //     return 0;
        // }
        vector<vector <int>> matrix(rows, vector<int>(cols));  // 注意这个构造函数的写法
        vector<int> resultVec;

        // 先给matrix赋值, 0表示未到达
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                matrix[i][j] = 0;
            }
        }

        return search(0, 0, threshold, matrix);
    }
};