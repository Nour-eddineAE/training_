from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        subset = []

        def dfs(pos):
            if pos >= len(nums):
                ans.append(subset[:])
                return

            subset.append(nums[pos])
            dfs(pos + 1)

            # ignore similar elements(if we consider them again we'll have duplicates)
            subset.pop()
            while pos < len(nums) - 1 and nums[pos + 1] == nums[pos]:
                pos += 1
            dfs(pos + 1)
        dfs(0)
        return ans


nums = [1, 2, 2]
# all possible subsets, duplicates are not allowed, same elements cannot be reused
# [[1, 2, 2], [1, 2], [1], [2, 2], [2], []]
print(Solution().subsetsWithDup(nums))
