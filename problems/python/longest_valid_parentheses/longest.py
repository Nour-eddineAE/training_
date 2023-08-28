class Solution:
    def longestValidParentheses(self, s: str) -> int:
        s = s[s.find('('): s.rfind(')') + 1]

        stack = []
        res = [0] * len(s)

        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    res[stack.pop()] = 1
                    res[i] = 1
        print(res)
        longest = 0
        temp = 0
        for val in res:
            if val != 0:
                temp += 1
            else:
                longest = max(longest, temp)
                temp = 0

        return max(temp, longest)


st = "(()(()(()))()()"
print(Solution().longestValidParentheses(st))  # 14
