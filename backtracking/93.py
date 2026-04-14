# 93. 复原ip地址
# 难度：中等

from typing import List

class Solution:

    def valid(self, s:str):
        if s.startswith('0') and len(s) != 1: return False
        elif int(s) < 0 or int(s) > 255: return False
        else: return True

    def restoreIpAddresses(self, s: str) -> List[str]:

        path = []
        ans = []
        total_put = 3

        def backtracking(start_index, to_put):
            if not to_put:
                if self.valid(s[start_index-1:]): 
                    path.append(s[start_index-1:])
                    ans.append('.'.join(path))
                    path.pop()
                    return
                else:
                    return
            
            begin = start_index - 1
            for i in range(start_index, len(s)):
                if not self.valid(s[begin:i]): continue
                path.append(s[begin:i])
                to_put -= 1
                backtracking(i+1, to_put)
                path.pop()
                to_put += 1

        backtracking(1, total_put)

        return ans

if __name__ == '__main__':
    s = Solution()
    ans = s.restoreIpAddresses('101023')
    print(ans)
                


