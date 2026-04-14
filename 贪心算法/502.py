from typing import List
import heapq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # profits和capital的原来顺序不变

        heap = [(-profits, idx) for idx, profits in enumerate(profits)]    # 构建capital的优先队列，默认实现是最小堆
        heapq.heapify(heap)

        temp_store = []

        cur = w # 当前的资金

        for _ in range(k):  # 进行k次投资
            candidate = None
            heap_l = len(heap)

            while(heap_l):
                poped = heapq.heappop(heap)
                heap_l -= 1

                profit, idx = poped
                profit = -profit

                if capital[idx] <= cur:
                    candidate = idx # 表示当前找到最大值
                    cur += profits[idx]
                    break
                else: temp_store.append(poped)  # 临时存储

            temp_l = len(temp_store)

            while(temp_l):  # 将剩余的temp送回heap
                heapq.heappush(heap, temp_store.pop())
                temp_l -= 1

            if candidate == None:   # 如果一个都没有找到，则判断没有可以执行的投资，则当前的资金就是最大资金
                break

        return cur

if __name__ == '__main__':
    s = Solution()
    res = s.findMaximizedCapital(2, 0, [1,2,3], [0, 1, 1])
    print(res)

