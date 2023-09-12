from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        cand = [0, []]

        def dfs(pos):
            if cand[0] == target:
                ans.append(cand[1].copy())
                return
            if pos >= len(candidates) or cand[0] > target:
                return

            tmp = candidates[pos]

            cand[0] += tmp
            cand[1].append(tmp)
            dfs(pos)

            cand[0] -= tmp
            cand[1].pop()
            dfs(pos + 1)

        dfs(0)

        return ans


candidates = [2, 3, 6, 7]
target = 7

# same elements may be reused
# [[2, 2, 3], [7]]
print(Solution().combinationSum(candidates, target))
