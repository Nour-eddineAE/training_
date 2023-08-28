from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        list_len = len(nums)

        if list_len > 1:
            greatestToTheRight = list_len - 1

            while greatestToTheRight > 0 and nums[greatestToTheRight - 1] >= nums[greatestToTheRight]:
                greatestToTheRight -= 1

            if greatestToTheRight == 0:
                nums = nums.reverse()
            else:
                to_swap_with = list_len - 1
                while to_swap_with >= 0 and nums[to_swap_with] <= nums[greatestToTheRight - 1]:
                    to_swap_with -= 1

                nums[greatestToTheRight -
                     1], nums[to_swap_with] = nums[to_swap_with], nums[greatestToTheRight - 1]

                nums[greatestToTheRight:] = reversed(nums[greatestToTheRight:])

            print(nums)


Solution().nextPermutation([1, 5, 4, 3, 2])  # [2, 1, 3, 4, 5]
