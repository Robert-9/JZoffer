/*
    描述
        输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字

    思路是将一圈分为四部分（四条边），逐条打印。打印一圈以后再往里缩一圈。
    Solution1 无法通过测试，Solution2可以。区别在于第2个和第3个for循环，i的取值范围
    因为行数和列数不一定相等，所以要在底部的边和左侧的边前加上判断，确保不重复计算。

    实际上相关的判断条件可以改
*/


#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int circles = (min(rows, cols) + 1) / 2;

        for(int circle=0; circle<circles; circle++){
            for(int i=circle; i<cols-circle-1; i++){  // 上面一行
                result.push_back(matrix[circle][i]);
            }
            for(int i=circle; i<rows-circle-1; i++){  // 右边一列
                result.push_back(matrix[i][cols-circle-1]);
            }
            
            if(rows-circle-1 > circle){  // 区分列数和行数不同的矩阵
                for(int i=cols-circle-1; i > circle; i--){  // 底下一行
                    result.push_back(matrix[rows-circle-1][i]);
                }   
            }
            if(cols-circle-1 > circle){
                for(int i=rows-circle-1; i>circle; i--){
                    result.push_back(matrix[i][circle]);
                }
            }
        }

        return result;
    }
};



#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int circles = (min(rows, cols) + 1) / 2;

        for (int circle = 0; circle < circles; circle++) {
            for (int i = circle; i < cols - circle-1; i++) { // 上面一行
                result.push_back(matrix[circle][i]);
            }
            for (int i = circle; i < rows - circle; i++) { // 右边一列
                result.push_back(matrix[i][cols - circle - 1]);
            }

            if (rows - circle - 1 > circle) {
                for (int i = cols - circle - 2; i > circle; i--) { // 底下一行
                    result.push_back(matrix[rows - circle - 1][i]);
                }
            }
            if (cols - circle - 1 > circle) {
                for (int i = rows - circle - 1 ; i > circle; i--) {
                    result.push_back(matrix[i][circle]);
                }
            }
        }

        return result;
    }
};