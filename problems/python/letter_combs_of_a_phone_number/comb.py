from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dig_to_str = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }

        res = []

        def bfs(pos, comb):
            if pos >= len(digits):
                res.append(comb)
                return

            for char in dig_to_str[digits[pos]]:
                bfs(pos + 1, comb + char)

        if digits:
            bfs(0, "")
        return res


# ['dg', 'dh', 'di', 'eg', 'eh', 'ei', 'fg', 'fh', 'fi']
print(Solution().letterCombinations("34"))
