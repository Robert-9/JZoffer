#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
        if(grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];

        for(int i=1; i<row; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int j = 1; j<col; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][col-1];

    }
};