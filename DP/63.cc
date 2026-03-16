/* 63. 不同路径II
 * 难度：中等
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = static_cast<int>(obstacleGrid.size()), n = static_cast<int>(obstacleGrid[0].size());
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        int tmp = 0;

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(obstacleGrid[i-1][j-1]) dp[i][j] = 0;
                if (i == 1 && j == 1) continue;
                if(i-2>=0 && j-1>=0 && !obstacleGrid[i-2][j-1]) dp[i][j] += dp[i-1][j];
                if(i-1>=0 && j-2>=0 && !obstacleGrid[i-1][j-2]) dp[i][j] += dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};

int main(void)
{
    auto s = Solution();
    vector<vector<int>> input({{0,1},{0,0}});
    s.uniquePathsWithObstacles(input);
}
