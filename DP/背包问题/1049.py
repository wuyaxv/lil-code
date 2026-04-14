# 1049. 最后一块石头的重量II
# 难度：中等
from typing import List
import math

class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        """策略
        将石头分为两个集合，一个集合是石头，另外一个是集合用来磨前一个集合
        集合A中所有石头为正，集合B中所有石头为负。
        最终磨损得到的石头是正的，也就是A中的石头之和会大于B。这个差值是多少？
        我们假设集合A、B的重量之和分别为sum(A), sum(B)
        Total = sum(A) + sum(B)
        C = sum(A) - sum(B) > 0
        Total + C = 2*sum(A) => sum(A) = (Total + C)/2
        Total - C = 2*sum(B) => sum(B) = (Total - C)/2
        要使得他们的差值C最小，则sum(B)就要尽可能的往Total/2去靠。
        所以整个问题可以看作是一个0-1背包问题，背包的容量是ceil(Total/2)
        物品的价值就是石头的重量，物品的重量也是石头的重量
        dp[j]: 背包容量为j时，我可以放置的最重石头
        不放：dp[i-1][j]
        放：dp[j-stones[i]]+stones[i]

        边界条件：

        """

        total = sum(stones)
        k = math.floor(total/2)
        dp = [0 for _ in range(k+1)]

        for i in range(len(stones)):
            for j in range(k, 0, -1):
                if j-stones[i] >= 0: dp[j] = max(dp[j], dp[j-stones[i]]+stones[i])

        return total-2*dp[-1]

if __name__ == '__main__':
    s = Solution()
    ans = s.lastStoneWeightII([31,26,33,21,40])
    print(ans)

        
