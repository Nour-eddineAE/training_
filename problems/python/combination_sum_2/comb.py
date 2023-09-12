from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(pos, total, comb):
            if total == target:
                ans.append(comb)
                return

            for i in range(pos, len(candidates)):
                if i > pos and candidates[i] == candidates[i - 1]:
                    continue  # Skip duplicates at the same level
                if total + candidates[i] > target:
                    return
                dfs(i + 1, total + candidates[i], comb + [candidates[i]])

        candidates.sort()
        ans = []
        dfs(0, 0, [])
        return ans


candidates = [10, 1, 2, 7, 6, 1, 5]
target = 8
# all possible combs that could sum up to target(duplicates not allowed)
# [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
print(Solution().combinationSum2(candidates, target))
