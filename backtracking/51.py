# 51. N皇后
# 难度：困难

from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:

        ans = []
        path = []
        encoded = []

        def back_tracking(loc, depth):
            if not depth: # n层深，说明此时已经找到了n个满足条件的值
                ans.append(path.copy())
                return

            for i in range(0, loc-1):
                depth -= 1
                if i not in path:
                    path.append(i)
                    back_tracking(i, depth)
                    path.pop()
                depth += 1

            for i in range(loc+2, n):
                depth-=1
                if i not in path:
                    path.append(i)
                    back_tracking(i, depth)
                    path.pop()
                depth+=1

        back_tracking(-2, n)

        for i in range(len(ans)):
            new = []
            for j in range(n): new.append(['.' for _ in range(n)])
            for j in range(n):
                new[j][ans[i][j]] = 'Q'
            encoded.append([''.join(l) for l in new])

        encoded.sort()

        return encoded
if __name__ == '__main__':
    s = Solution()
    print(s.solveNQueens(9))


