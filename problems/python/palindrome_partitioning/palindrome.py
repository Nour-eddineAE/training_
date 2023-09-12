from typing import List


class Solution:
    def isPalindrome(self, s):
        s_len = len(s)
        for i in range(s_len // 2):
            if s[i] != s[s_len - i - 1]:
                return False
        return True

    def partition(self, s: str) -> List[List[str]]:
        ans = []
        s_len = len(s)

        def dfs(pos, part):
            if pos >= s_len:
                ans.append(part)
                return

            for j in range(pos, s_len):
                if self.isPalindrome(s[pos: j + 1]):
                    dfs(j + 1, part + [s[pos: j + 1]])

        dfs(0, [])
        return ans


print(Solution().partition("aab"))  # [['a', 'a', 'b'], ['aa', 'b']]
