from typing import List

# ! The overall complexity of the algorithm must be logn
# ! The current solution is O(logn) but there's a better one
# ! However, this one is quite easier to understand and remember


class Solution:
    def bin_search(self, nums, target) -> int:
        start = 0
        end = len(nums) - 1

        while start <= end:
            mid = int((start + end) / 2)
            if nums[mid] < target:
                start = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                return mid

        return -1

    def search(self, nums: List[int], target: int) -> int:
        arr_len = len(nums)

        if arr_len == 1:
            return 0 if nums[0] == target else -1

        start = 0
        end = arr_len - 1

        piv = 0

        while start <= end:
            mid = int((start + end) / 2)

            if mid + 1 < arr_len and nums[mid] > nums[mid + 1]:
                piv = mid + 1
                break

            elif nums[mid] <= nums[-1]:
                end = mid - 1
            elif nums[mid] > nums[-1]:
                start = mid + 1

        if target >= nums[piv] and target <= nums[-1]:
            res = self.bin_search(nums[piv:], target)
            return res + piv if res != -1 else res
        else:
            return self.bin_search(nums[:piv], target)


nums = [5, 1, 3]
print(Solution().search(nums, 2))  # -1(unfound)
