from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        len_nums = len(nums)

        if len_nums == 1:
            return [nums[:]]

        ans = []
        for i in range(len_nums):
            front = nums.pop(0)

            perms = self.permute(nums)
            for perm in perms:
                perm.append(front)

            nums.append(front)

            ans.extend(perms)
        return ans


# [[3, 2, 1], [2, 3, 1], [1, 3, 2], [3, 1, 2], [2, 1, 3], [1, 2, 3]]
print(Solution().permute([1, 2, 3]))
