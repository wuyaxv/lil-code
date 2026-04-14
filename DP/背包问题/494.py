# 494. 目标和
# 难度：中等

"""
将集合分为两组A，B
A：符号为+
B：符号为-
sum(A) - sum(B) = target
sum(A) + sum(B) = total
sum(A) = (target+total)/2

问题转化为一个0-1背包问题
放哪些元素可以得到sum(A)？
"""

from typing import List

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        count = 0 # 每一轮计数一次
        t = sum(nums) + target
        if t % 2: return 0

        sumA = int(t/2)

        dp = [0 for _ in range(sumA+1)]

        for i in range(len(nums)):
            print(dp)
            for j in range(sumA, 0, -1):
                if j-nums[i] >= 0:
                    # dp[j]: 满足sumA == j的有多少种情况？
                    

        return count

if __name__ == '__main__':
    s = Solution()
    nums = [1,1,1,1,1]
    target = 3
    ans = s.findTargetSumWays(nums, target)
    print(ans)
