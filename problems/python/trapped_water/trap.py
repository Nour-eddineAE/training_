from typing import List

"""
# Original sol, O(n) space
class Solution:
    def trap(self, height: List[int]) -> int:
        height_len = len(height)

        if height_len <= 2:
            return 0

        left_max = [0] * height_len
        right_max = [0] * height_len

        left_max[0] = height[0]
        for i in range(1, height_len):
            left_max[i] = max(left_max[i - 1], height[i])

        right_max[height_len - 1] = height[height_len - 1]
        for i in range(height_len - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])

        count = 0
        for i in range(1, height_len - 1):
            min_boundary = min(left_max[i], right_max[i])
            if min_boundary > height[i]:
                count += min_boundary - height[i]

        return count


"""


class Solution:
    def trap(self, height: List[int]) -> int:
        """
        ? 1- The trick lies in the fact that if we have a larger boundary to the right than to the left, 
            the maximum number of water units we can form is determined by the minimum among right and left boundaries,
            we just need -for each index in the array- to substract the height of the boundary itself
        ? 2- Same thing applies when the left boundary is larger than the right one
        ? 3- If they are equal, then whatever pointer we move will be valid
        """
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]

        count = 0
        while left < right:
            if left_max < right_max:
                left += 1
                left_max = max(left_max, height[left])
                # if current height is larger, we increment by 0, otherwise we increment by left_max - the current height
                count += left_max - height[left]
            else:
                right -= 1
                right_max = max(right_max, height[right])
                # if current height is larger, we increment by 0, otherwise we increment by right_max - the current height
                count += right_max - height[right]
        return count


arr = [100000, 0, 99999, 0, 99998, 0, 99997, 0, 99996, 0, 99995, 0, 99994, 0, 99993, 0, 99992, 0, 99991, 0, 99990, 0, 99989, 0, 99988, 0, 99987,
       0, 99986, 0, 99985, 0, 99984, 0, 99983, 0, 99982, 0, 99981, 0, 99980, 0, 99979, 0, 99978, 0, 99977, 0, 99976, 0, 99975, 0, 99974, 0, 99973]
print(Solution().trap(arr))  # 2699622
