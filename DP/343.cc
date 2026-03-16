/* 343. 整数拆分
 * 难度：中等
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        int max = 0;
        int temp = 0;
        int a, b;

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; ++i) {
            max = 0;
            for(int j = 1; j <= static_cast<int>(i/2); ++j) {
                if(dp[j] < j) a = j;
                else a = dp[j];

                if(dp[i-j] < i-j) b = i-j;
                else b = dp[i-j];

                temp = a * b;

                if(temp>max) max = temp;
            }
            dp[i] = max;
        }

        return dp[n];
    }
};

int main(void)
{
    auto  s = Solution();
    int result = s.integerBreak(10);

    std::cout << result << endl;
}
