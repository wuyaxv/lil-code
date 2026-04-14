"""
502. IPO
难度：困难

说明：这题是0-1背包问题的变体
"""
from typing import List

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)

        dp = [w for _ in range(k+1)]

        items = list(zip(profits, capital))
        items.sort(key=lambda k: k[1]) # 对capital进行排序

        for i in range(n):
            for j in range(k, 0, -1):
                if dp[j-1] >= items[i][1]: # 可以投
                    dp[j] = max(dp[j], dp[j-1]+items[i][0]) # 判断投还是不投
        return dp[-1]

if __name__ == '__main__':
    k = 2
    w = 0
    profits = [1,2,3]
    capital = [0,1,1]

    s=Solution()
    s.findMaximizedCapital(k,w,profits,capital)

