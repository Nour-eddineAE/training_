from collections import Counter
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqs_sorted = sorted(Counter(nums).items(), key=lambda item: item[1])
        return [item[0] for item in freqs_sorted[len(freqs_sorted) - k:]]


nums = [1, 1, 1, 2, 2, 3]
k = 2

print(Solution().topKFrequent(nums, k))  # Output: [1,2]
