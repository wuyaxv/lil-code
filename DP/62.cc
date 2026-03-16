/* 62. 不同路径
 * 难度：中等
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i = 0, j = 0;
        int dp[100+1][100+1] = {0};
        dp[1][1] = 1;

        for(i = 1; i <= m; ++i) {
            for(j = 1; j <= n; ++j) {
                if(i == 1 && j == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        for(i = 1; i <= m; ++i) {
            for(j = 1; j <= n; ++j) {
                std::cout << dp[i][j] << " ";
            }
            std::cout << std::endl;
        }

        return dp[m][n];
    }
};

int main(void)
{
    auto s = Solution();
    int result = s.uniquePaths(3, 3);
}
