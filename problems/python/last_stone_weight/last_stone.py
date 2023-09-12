import heapq
from typing import List


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # simulate a MaxHeap with a MinHeap
        for i in range(len(stones)):
            stones[i] = -stones[i]

        heapq.heapify(stones)
        while len(stones) >= 2:
            diff = heapq.heappop(stones) - heapq.heappop(stones)
            if diff != 0:
                heapq.heappush(stones, diff)

        return -stones[0] if stones else 0


print(Solution().lastStoneWeight([2, 7, 4, 1, 8, 1]))  # 1
