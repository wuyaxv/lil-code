from typing import List
import math

class Solution:
    def numSquares(self, n: int) -> int:
        sqrt_nums = math.floor(math.sqrt(n))
        nums = [num**2 for num in range(1, sqrt_nums+2)]
        dp = [ [0] * sqrt_nums for _ in range(n+1) ]

        total = [0,]

        for i in range(1, n+1):
            for j in range(sqrt_nums+1):
                if i-nums[j] > 0:
                    dp[i][j] = total[i-nums[j]]
                elif i == nums[j]:
                    dp[i][j] = 1
                else:
                    total.append(sum(dp[i]))
                    break
        
        # find the path
        path = []

        value = n # value初始值一定不是0，因为至少全1满足题意
        next_i: int = n
        next_j: int = nums[-2]
        while value != 0:
            current_j = next_j
            value -= nums[next_j]
            path.append(nums[next_j])
            for j in range(next_j, -1, -1):
                if dp[next_i][j] != 0:
                    next_j = j
                    break

            






if __name__ == '__main__':
    n = 7
    s = Solution()
    ans = s.numSquares(n)

