from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0 for _ in range(amount+1)]
        dp[0] = 1

        for coin in coins:
            for j in range(amount+1):
                if j >= coin:
                    dp[j] += dp[j-coin]
        return dp[-1]

if __name__ == '__main__':
    amount = 10
    coins = [10]
    s = Solution()
    ans = s.change(amount, coins)
    print(ans)

