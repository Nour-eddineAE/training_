from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        """
          * check for first occurence, then check again for last occurence
        """
        def binary_search(arr, targ, len_arr, find_last=False):
            start = 0
            end = len_arr - 1
            result = -1

            while start <= end:
                mid = (start + end) // 2
                if arr[mid] == targ:
                    result = mid
                    if find_last:
                        start = mid + 1
                    else:
                        end = mid - 1
                elif arr[mid] < targ:
                    start = mid + 1
                else:
                    end = mid - 1

            return result

        len_arr = len(nums)
        first_occurrence = binary_search(nums, target, len_arr)
        last_occurrence = binary_search(nums, target, len_arr, True)

        return [first_occurrence, last_occurrence]


nums = [2, 2]

print(Solution().searchRange(nums, 2))  # [0, 1]
