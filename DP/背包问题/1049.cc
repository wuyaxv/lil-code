/* 1049. 最后一块石头的重量 II
 * 难度：中等
 *
 * 思路：
 * 这一题的本质是一个0-1背包问题。难点在于，需要分析问题将其转化为一个0-1背包问题。
 * 在Leetcode中，也需要注意分析问题，将问题转化为0-1背包问题是很多问题的实际难点，而使用动态规划来解决本身
 * 其实是很简单。
 *
 * 本题的主要思路是将石头分为两给石头堆，最终的得到的石头重量就是这两个石头堆的重量差。
 * 合法性证明：
 * 为了便于讨论，如果没有石头了，视为留下了一块质量为0的石头。
 * 最后一块石头可以表示为 $\sum_{i=0}^{n-1} k_i \times stones_i$, 其中 $k_i \in \{-1, +1\}$.
 * 可以将前 n-1 个石头分为两堆，一堆放在A，k_i = +1，另一堆放在B，k_i = -1;
 *
 * DP解决此问题：
 * 记石头的总重量为 sum，更小的那个堆的总重量为 neg，则最后得到的石头的重量为 (sum-neg)-neg = sum - 2*neg
 * sum-2*neg > 0 => neg < sum/2
 * 则可以将这个neg堆开做一个背包问题，其最大为 sum/2 的下界。
 * 放置的内容为所有石头。然后按照0-1背包问题解决这个问题即可。
 *
 * 在0-1背包问题中，可以考虑将dp数组初始化为 sum/2+1 x stones.size()+1大小，这样，可以将没有放置石头的行设置为0，将质量为0的行设置为0，简化状态转移方程。
 */

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

// #define min(a, b) (((a) < (b)) ? (a) : (b))

int lastStoneWeightII(vector<int>& stones) {
    int sum = std::accumulate(stones.begin(), stones.end(), 0);
    int volume = static_cast<int>(sum/2);
    int answer = 0;

    vector<vector<int>> dp(stones.size()+1, vector<int>(volume+1, 0)); // volume+1 x stones.size()+1
    
    for(int i = 1; i <= static_cast<int>(stones.size()); ++i) { // 遍历石头
        for(int j = 1; j <= volume; ++j) {// 遍历背包容积
            if(stones[i-1] > j) {
                dp[i][j] = dp[i-1][j];  // 新的石头放不下，也只有和旧的石头放置相同
            } else {
                dp[i][j] = max(
                        dp[i-1][j], // 不放置
                        dp[i-1][j-stones[i-1]] + stones[i-1] // 放置
                        );
            }
        }
    }
    for(int i = 0; i <= static_cast<int>(stones.size()); ++i) { // 遍历石头
        for(int j = 0; j <= volume; ++j) {// 遍历背包容积
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    answer = sum - 2 * dp[stones.size()][volume];
    return answer;
}

int main(void)
{
    vector<int> input({31,26,33,21,40});

    std::cout << lastStoneWeightII(input);
}
