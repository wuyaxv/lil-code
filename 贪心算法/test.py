import heapq
from typing import List
import sys

def sol(k: int, m: int, costs: List[int], profits: List[int]) -> int:
    heap = [(-profit, idx) for idx, profit in enumerate(profits)]
    heapq.heapify(heap)
    temp = []
    
    cur = m # 初始资金为m
    
    for i in range(k):
        candidate = None     
        heap_l = len(heap)
        while(heap_l):
            poped = heapq.heappop(heap)
            heap_l -= 1
            profit, idx = -poped[0], poped[1]
            
            if costs[idx] <= cur:
                cur += profit
                candidate = poped
                print(f"Choose: {idx} => ({costs[idx]}, {profits[idx]}). {cur-profit} + {profit} = {cur}")
                break
            else:
                temp.append(poped)
        
        temp_l = len(temp)
        while(temp_l):
            heapq.heappush(heap, temp.pop())
            temp_l -= 1
        if not candidate: # 没有找到合适的投资
            break
    return cur-m
      

if __name__ == '__main__':
    inputs = []

    for line in sys.stdin:
        if not line.rstrip(): break
        else:
            inputs.append(line.rstrip())

    k = int(inputs[0])
    m = int(inputs[1])
    costs = list(map(int, inputs[2].split()))       # 成本价
    benifits = list(map(int, inputs[3].split()))    # 利润

    print(sol(k, m, costs, benifits))

