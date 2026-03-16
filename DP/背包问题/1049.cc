/* 1049. 最后一块石头的重量 II
 * 难度：中等
 *
 * 思路：
 *
 *
 */

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int lastStoneWeightII(vector<int>& stones) {
    vector<int> dp(stones.size()+1, 0);   

    for(int i = 0; i < stones.size(); ++i) {
        dp[i+1] = min(abs(dp[i]+stones[i]), abs(dp[i]-stones[i]));
    }

    for(auto iter = dp.begin(); iter != dp.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return dp.back();
}

int main(void)
{
    vector<int> input({2,7,4,1,8,1});

    std::cout << lastStoneWeightII(input);
}
