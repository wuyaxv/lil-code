/* 746. 使用最小花费爬楼梯
 * 难度：简单
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <array>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top = static_cast<int>(cost.size());
        int *dp = new int[top];
        int result = 0;

        dp[0] = 0;
        dp[1] = 0;

        int i = 2;
        while(i <= top) {
            dp[i++] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        result = dp[top];

        delete[] dp;
        dp = nullptr;

        return result;
    }
};

int main(void)
{
    auto s = Solution();
    vector<int> cost{10, 15, 20};
    int result = s.minCostClimbingStairs(cost);

    std::cout << result;
}

