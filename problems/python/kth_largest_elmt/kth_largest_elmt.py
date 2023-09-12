import heapq
from typing import List


class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.nums = nums
        heapq.heapify(self.nums)
        while len(self.nums) > k:
            heapq.heappop(self.nums)

    def add(self, val: int) -> int:
        hp_min = heapq.heappop(self.nums)
        heapq.heappush(self.nums, max(val, hp_min))
        return self.nums[0]


cl = KthLargest(3, [4, 5, 8, 2])
print(cl.add(7))  # 5
