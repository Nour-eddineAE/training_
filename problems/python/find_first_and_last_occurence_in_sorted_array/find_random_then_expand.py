from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        """
         * check for some random occurence, then start checking for neighbors
        """
        def bin_search(arr, targ, len_arr) -> int:
            start = 0
            end = len_arr - 1

            while start <= end:
                mid = (start + end) // 2
                if arr[mid] < targ:
                    start = mid + 1
                elif arr[mid] > targ:
                    end = mid - 1
                else:
                    return mid
            return -1

        len_arr = len(nums)
        pos = bin_search(nums, target, len_arr)

        if pos == -1:
            return [-1, -1]

        low, high = pos, pos
        while high < len_arr and low >= 0:
            if high < len_arr - 1 and nums[high + 1] == target:
                high += 1

            if (low > 0 and nums[low - 1] == target):
                low -= 1

            if (((low > 0 and nums[low - 1] != target) or low == 0) and (high == len_arr - 1 or (high < len_arr - 1 and nums[high + 1] != target))):
                break

        return [low, high]


nums = [2, 2]

print(Solution().searchRange(nums, 2))  # [0, 1]
