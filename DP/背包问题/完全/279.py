from typing import List
import math
from pprint import pprint

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

        res = []
        def back_tracking(dp, i, path):
            if i == 0:
                res.append(path.copy())
                return
        
            for j in range(sqrt_nums-1, -1, -1):
                if dp[i][j] != 0: 
                    path.append(nums[j])
                    i -= nums[j]
                    back_tracking(dp, i, path)
                    i += nums[j]
                    path.pop()

        
        # find the path
        path = []
        i = n
        back_tracking(dp, i, path)
        minimum = 200000
        for i in res:
            length = len(i)
            minimum = length if length < minimum else minimum
        pprint(dp)
        return minimum


if __name__ == '__main__':
    n = 12
    s = Solution()
    ans = s.numSquares(n)
    print(ans)

