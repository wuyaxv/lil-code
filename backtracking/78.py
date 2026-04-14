from typing import List, Dict

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        path = []
        ans = []
        self.backtracking(nums, path, ans, 0)
        return ans

    def backtracking(self, nums, path: List, ans, start_index):
        ans.append(path.copy())
        
        for i in range(start_index, len(nums)):
            path.append(nums[i])
            self.backtracking(nums, path, ans, i+1)
            path.pop()

if __name__ == '__main__':
    s = Solution()
    print(s.subsets([1,2,3]))
            


        
