/*
    描述
    请设计一个函数，用来判断在一个n乘m的矩阵中,是否存在一条,包含某长度为len的字符串所有字符,的路径。
    路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
    如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
*/
#include <vector>
#include <string>
using namespace std;


class Solution {
private:
    bool hasNext(int x, int y, int pathLen, string word, vector<vector<char> >& matrix){
        /*
        @brief: 在指定位置的元素周围相邻位置找下一个节点
        @param: 
            dir: 来的方向 1 从左往右  2 从上往下  3 从右往左 4 从下往上
            wordLen: 当前的长度
        */       
        if(pathLen == word.size()){
            return true;
        }
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y] != word[pathLen]){
            return false;
        }

        char temp = matrix[x][y];
        matrix[x][y] = '#';  // 不为26个字母的都可以，用于标记已经走过的路径
        bool found = hasNext(x+1, y, pathLen, word, matrix) ||
                hasNext(x-1, y, pathLen, word, matrix) ||
                hasNext(x, y+1, pathLen, word, matrix) ||
                hasNext(x, y-1, pathLen, word, matrix);
        matrix[x][y] = temp;

        return found;
        
        // if(matrix[x][y] == word[pathLen]){
        //     pathLen++;
        //     // 移动节点
        //     if(dir == 1){ // 
        //         if(x == 0) {
        //             return hasNext(x, y+1, 1, pathLen, word, matrix) ||
        //                 hasNext(x+1, y, 2, pathLen, word, matrix);
        //         }
        //         else if(x == matrix.size()){
        //             return hasNext(x, y+1, 1, pathLen, word, matrix) ||
        //                 hasNext(x-1, y, 4, pathLen, word, matrix);
        //         }
        //         else if(y == matrix[0].size()){
        //             return hasNext(x+1, y, 2, pathLen, word, matrix) ||
        //                 hasNext(x-1, y, 4, pathLen, word, matrix);
        //         }
        //         else{
        //             return hasNext(x, y+1, 1, pathLen, word, matrix) ||
        //                 hasNext(x+1, y, 2, pathLen, word, matrix) ||
        //                 hasNext(x-1, y, 4, pathLen, word, matrix);
        //         }
        //     } 
        //     else if(dir == 2){ // 
        //         x = x + 1;
        //     } 
        //     else if(dir == 3){ // 
        //         y = y - 1;
        //     } 
        //     else if(dir == 4){ // 
        //         x = x - 1;
        //     }
        // }
        // else return false;
    }
public:
    bool hasPath(vector<vector<char> >& matrix, string word) {
        /*
            在矩阵中遍历，找到字符串头
        */
       int col = matrix[0].size();
       int row = matrix.size();
       
       // 为空的判断
        if (matrix.empty() || word.empty()) {
	         return false;
        }

        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){
                if(matrix[j][i] == word[0]){
                    if(hasNext(j, i, 0, word, matrix)) return true;
                }
            }
        }
        return false;
    }
};