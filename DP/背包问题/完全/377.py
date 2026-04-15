from typing import List
import math

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        total = [0] * (target + 1)
        total[0] = 1

        dp = [0] * len(nums)
        count = 0

        for i in range(1, target+1):
            for j in range(len(nums)):
                if i >= nums[j]:
                    dp[j] = total[i-nums[j]]
            total[i] = sum(dp)

        return total[-1]
if __name__ == '__main__':
    nums = [1,2,3]
    target = 4
    s = Solution()
    ans = s.combinationSum4(nums, target)
    print(ans)

