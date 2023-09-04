from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        longest, low, high = 1, 0, 0
        sorted_nums = sorted(set(nums))
        len_sorted_nums = len(sorted_nums)

        while low <= high and high < len_sorted_nums - 1:
            if sorted_nums[high] + 1 == sorted_nums[high + 1]:
                high += 1
            else:
                longest = max(longest, high - low + 1)
                high += 1
                low = high

        # we still return the max(in case all elements were consecutive, the "else" will never be executed)
        return max(longest, high - low + 1)


print(Solution().longestConsecutive([100, 4, 200, 1, 3, 2]))  # 4
