from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        path = []
        ans = []

        def back_tracking(start_index):
            if start_index == len(s)+1: 
                ans.append(path.copy())
                return

            begin = start_index-1
            for i in range(start_index, len(s)+1):
                if not self.is_palindrom(s[begin:i]): continue
                path.append(s[begin:i])
                back_tracking(i+1)
                path.pop()

        back_tracking(1)

        return ans


    def is_palindrom(self, s: str):
        l_ptr = 0
        r_ptr = len(s)-1
        while l_ptr < r_ptr:
            if(s[l_ptr] != s[r_ptr]): return False
            l_ptr += 1
            r_ptr -= 1
        return True


if __name__ == '__main__':
    s = Solution()
    print(s.partition("aab"))
