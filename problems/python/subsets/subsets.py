from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []

        subset = []

        def dp(pos):
            if pos >= len(nums):
                ans.append(subset.copy())
                return

            # include current elmt
            subset.append(nums[pos])
            dp(pos + 1)

            # not include current elmt
            subset.pop()
            dp(pos + 1)
        dp(0)
        return ans


# dups are not allowed, elements are unique
# [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3], []]
print(Solution().subsets([1, 2, 3]))
