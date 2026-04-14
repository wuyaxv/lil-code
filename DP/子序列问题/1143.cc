/* 1143. 最长公共子序列
 * 难度：中等
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        
        for(auto i = 1; i < text1.size()+1; ++i) {
            for(auto j = 1; j < text2.size()+1; ++j) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

int main(void)
{
    auto s = Solution();
    string text1 = "";
    string text2 = "";
    int result = s.longestCommonSubsequence(text1, text2);
    std::cout << result;
}
