from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        len_temp = len(temperatures)

        if len_temp <= 1:
            return [0]

        stack = []
        res = [0] * len_temp

        pointer = 0
        for pointer, temp in enumerate(temperatures):
            while stack and stack[-1][1] < temp:
                idx, _ = stack.pop()
                res[idx] = pointer - idx

            stack.append((pointer, temp))

        return res


temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
# for each day, how many days should we wait to get warmer
# [1, 1, 4, 2, 1, 1, 0, 0]
print(Solution().dailyTemperatures(temperatures))
