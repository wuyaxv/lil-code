# 416. 分割等和子集
# 难度：中等

"""
这题难度应该比1049. 求最小子集和之差的难度小
"""

from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        _sum = sum(nums)
        if _sum % 2: return False

        half = int(_sum/2)

        dp = [0 for _ in range(half+1)]
        for i in range(len(nums)):
            for j in range(half, 0, -1):
                if j-nums[i] >= 0: dp[j] = max(dp[j], dp[j-nums[i]] + nums[i])

        if dp[-1] == half: return True
        else: return False

if __name__ == '__main__':
    s = Solution()
    print(s.canPartition([1,5,11,5]))
