#include <vector>
#include <algorithm>
using namespace std;



#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int circles = (min(rows, cols) + 1) / 2;  // 计算需要循环的圈数

        for(int circle = 0; circle < circles; circle++){
            // 上面一行
            for(int i = circle; i < cols - circle; i++) {
                result.push_back(matrix[circle][i]);
            }
            // 右边一列
            for(int i = circle + 1; i < rows - circle; i++) {
                result.push_back(matrix[i][cols - circle - 1]);
            }
            // 底下一行
            if (rows - circle - 1 > circle) {  // 需要判断是否是同一行
                for(int i = cols - circle - 2; i >= circle; i--) {
                    result.push_back(matrix[rows - circle - 1][i]);
                }
            }
            // 左边一列
            if (cols - circle - 1 > circle) {  // 需要判断是否是同一列
                for(int i = rows - circle - 2; i > circle; i--) {
                    result.push_back(matrix[i][circle]);
                }
            }
        }

        return result;
    }
};


class Solution2 {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 从左到右打印上边的一行
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // 从上到下打印右边的一列
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // 从右到左打印下边的一行（确保还有行可以打印）
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // 从下到上打印左边的一列（确保还有列可以打印）
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};
