from typing import List

"""
# Original code, O(n) auxilary space
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr_len = len(nums)
        prefixes, suffixes = [1] * arr_len, [1] * arr_len

        for i in range(arr_len):
            if i > 0:
                prefixes[i] = prefixes[i - 1] * nums[i - 1] 
        for i in range(arr_len - 1, -1, -1):
            if i < arr_len - 1:
                suffixes[i] = suffixes[i + 1] * nums[i + 1]
        
        res = []
        for i in range(arr_len):
            res.append(prefixes[i] * suffixes[i])
            
        return res 
"""

# Optimized code, O(1) space


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr_len = len(nums)

        if nums.count(0) >= 2:
            return [0] * arr_len

        res = [1] * arr_len
        left_product, right_product = 1, 1

        for i in range(arr_len):
            res[i] *= left_product
            left_product *= nums[i]

        for i in range(arr_len - 1, -1, -1):
            res[i] *= right_product
            right_product *= nums[i]

        return res


nums = [1, 2, 3, 4]

print(Solution().productExceptSelf(nums))  # Output: [24,12,8,6]
